# SFML - Arma
## _by Polina Chubenko_
____

A strategy game - fight of units - made in C++ using sfml library. It seems to be ✨Magic ✨

## Requirements
____

#### Must have (dependencies)
- SFML 2.4.1 or above - http://www.sfml-dev.org/
##### Linux
```sh
 sudo apt-get install libsfml-dev
```

## Building from source
____

- Download the source code.
- Don't forget to install the sfml libraries.
- Use `run.sh` file to run the project and then enjoy the game
> Note: In case you installed SFML to a non-standard path, you'll need to tell the compiler where to find the SFML headers (.hpp files), so in `run.sh` file set last three commands as it is written :
```sh
g++ -c main.cpp -I<sfml-install-path>/include
g++ main.o -o sfml-app -L<sfml-install-path>/lib -lsfml-graphics -lsfml-window -lsfml-system
export LD_LIBRARY_PATH=<sfml-install-path>/lib && ./sfml-app
```

