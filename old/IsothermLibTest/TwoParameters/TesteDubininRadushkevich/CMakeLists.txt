# Define o nome do executável e do arquivo de teste
set(IsothermExe "TesteDubininRadushkevich")
set(IsothermFile "${IsothermExe}.cpp")

# Configura o diretório de saída para o executável do teste
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")

# Adiciona o executável do teste usando a função customizada
add_test_executable(${IsothermExe} ${IsothermFile})
