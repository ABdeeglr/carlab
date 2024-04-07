#define DEBUG
#include "head.h"

int get_random_integer(int boundary);

int main(int argc, const char* argv[]) {

    int sum = 0;
    int speed;
    puts("Do you want to enable better integration of stack with GHCup?\n"
         "This means that stack won't install its own GHC versions, but uses GHCup's.\n"
         "For more information see:\n\t"
         "https://docs.haskellstack.org/en/stable/yaml_configuration/#ghc-installation-customisation-experimental");

    
    while (sum <= 2048 * 2048) {
        speed = get_random_integer(2048);

    }
    
    return 0;
}

int get_random_integer(int boundary) {
    int ret = rand() % boundary;
    return ret;
}