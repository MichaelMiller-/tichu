##include_directories(${CMAKE_CURRENT_LIST_DIR})

find_package(Boost REQUIRED)

function(test test)
    string(REPLACE "/" "_" tmp ${test})
    add_executable(test.${tmp} "${CMAKE_CURRENT_LIST_DIR}/${test}.cpp")

    target_include_directories(test.${tmp} PRIVATE "${CMAKE_SOURCE_DIR}/deps/range-v3/include")

    add_compile_options(-Wall -Wextra -Wpedantic -Wconversion)

    target_link_libraries(test.${tmp} PUBLIC tichu)

    add_test(test.${tmp} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test.${tmp}")
endfunction()

## unit tests via catch (alphabetical order)
##
test("cards")
test("views")
test("logic.is_pair")
test("logic.is_trio")
# test("logic.full_house")
test("logic.is_straight")
test("logic.is_bomb")
test("logic.is_continuous")
# test("logic.kind")
