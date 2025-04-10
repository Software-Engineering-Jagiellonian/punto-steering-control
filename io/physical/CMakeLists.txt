 
file(GLOB ELECTRONICS_LAYER_SRC
    "*.cpp"
    "*.h"
)

add_library(electronics_layer STATIC ${ELECTRONICS_LAYER_SRC})