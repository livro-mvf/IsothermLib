
set (       IsothermExe
            "TesteLangmuir"
            )

set (       IsothermFile
            "TesteLangmuir.cpp"
            )



set     (   CMAKE_RUNTIME_OUTPUT_DIRECTORY
            "${CMAKE_CURRENT_LIST_DIR}"
            )

add_executable  (   ${IsothermExe}
                    ${IsothermFile}
                    )

target_include_directories  (   ${IsothermExe}
                                PRIVATE
                                "${CMAKE_SOURCE_DIR}/IsothermLib/include"
                                )

target_link_libraries   (   ${IsothermExe}
                            PRIVATE
                            IsothermLib
                            ${GTEST_LIBRARIES} 
                            pthread
                        )


add_test(NAME ${IsothermExe} COMMAND ${IsothermExe})