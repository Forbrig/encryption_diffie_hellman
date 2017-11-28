# Caesar Cipher

Caesar Cipher is one of the most known encryption algorithm. See more at [Wiki](https://en.wikipedia.org/wiki/Caesar_cipher).

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

To compile you need to have **gcc** (or equivalent) on your machine.  

### Installing

After maching prerequisites you need to compile the cesar algorithm and its breaker. Type in terminal _(on cesar folder)_:

```
$ make main
```

If you already have the files compiled and need to remove it:  

```
$ make clean
```
Run the application:

```
$ ./cesar
```

## Running the tests

* You can look at the contents of message and encrypted message on terminal.  
* You can change the message that you want to encrypt in **/test/test1.txt**.  
* You can have a look at the encrypted message in **/test/out1.txt**.  
* The **key** (an integer) for caerser is inserted manually via terminal.  
* Breaker try to breake the encrypted message in **/test/out1.txt**.
* You can change the words on **dictionary.dat**, the algorithm break the words by space.

### Breaker the encryption

* The breaker is a brute force algorithm that try all the 256 keys possibilities (number of chars in _ascii_). For each possibilitie it break the resultant string in words by space and see if there is a word that match equaly in **dictionary.dat**.

## Authors

* **Vitor G. Forbrig** - [Forbrig](https://github.com/Forbrig)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
