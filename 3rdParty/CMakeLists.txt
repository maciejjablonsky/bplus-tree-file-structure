add_subdirectory(fmt)
set_target_properties(fmt PROPERTIES FOLDER 3rdParty/fmt)

add_subdirectory(googletest)
set_target_properties(gtest PROPERTIES FOLDER 3rdParty/googletest)
set_target_properties(gtest_main PROPERTIES FOLDER 3rdParty/googletest)
set_target_properties(gmock PROPERTIES FOLDER 3rdParty/googletest)
set_target_properties(gmock_main PROPERTIES FOLDER 3rdParty/googletest)

add_subdirectory(cxxopts)
set_target_properties(options_test PROPERTIES FOLDER tests)
set_target_properties(link_test PROPERTIES FOLDER 3rdParty/cxxopts)
set_target_properties(example PROPERTIES FOLDER 3rdParty/cxxopts)