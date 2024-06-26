cmake_minimum_required(VERSION 3.15)

project(IsothermLib
        VERSION 1.0.1
        DESCRIPTION "Biblioteca Isotherm++"
        LANGUAGES CXX)

# Configuração do padrão C++ para C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Opções de compilação para otimização
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fassociative-math -freciprocal-math -fno-signed-zeros -fno-trapping-math")

# Opção para construir testes
option(BUILD_TESTS "Compilar os programas de teste" OFF)

# Adiciona o diretório da biblioteca principal
add_subdirectory(IsothermLib)

# Mensagem para indicar se os testes serão compilados
message(STATUS "BUILD_TESTS=${BUILD_TESTS} -> Compilar os testes")

# Lista de executáveis de teste
set(TEST_EXECUTABLES "")

# Função para adicionar executáveis de teste e alvos de execução
function(add_test_executable TARGET_NAME TARGET_FILE)
    add_executable(${TARGET_NAME} ${TARGET_FILE})
    target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/IsothermLib/include")
    target_link_libraries(${TARGET_NAME} PRIVATE IsothermLib ${GTEST_LIBRARIES} pthread)
    add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
    list(APPEND TEST_EXECUTABLES ${TARGET_NAME})
    set(TEST_EXECUTABLES "${TEST_EXECUTABLES}" PARENT_SCOPE)
endfunction()

# Se a opção de testes estiver ativada, adicionar o subdiretório dos testes
if(BUILD_TESTS)
    # Inclui Google Test
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    
    # Adiciona o diretório de testes
    add_subdirectory(IsothermLibTest)
    
    # Habilita o sistema de testes do CMake
    enable_testing()

    # Cria um alvo customizado para rodar todos os exemplos
    add_custom_target(run_all_examples
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        DEPENDS ${TEST_EXECUTABLES}
        COMMENT "Executando todos os exemplos de teste"
    )
endif()
