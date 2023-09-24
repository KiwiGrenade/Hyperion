add_library(FileRendering Render.cpp)
add_library(VectorLib Vectors.h)
set_target_properties(VectorLib PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(FileRendering VectorLib)
