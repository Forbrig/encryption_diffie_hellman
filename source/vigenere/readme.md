# Vigenere Cipher

Vigenere Cipher is a Caesar Cipher a bit more complex. See more at [Wiki](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher).

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

To compile you need to have **gcc** on your machine.  

### Installing

After maching prerequisites you need to compile the vigenere algorithm and its breaker. Type in terminal _(on vigenere folder)_:

```
$ make main
```

If you already have the files compiled and need to remove it:  

```
$ make clean
```
Run the application:

```
$ ./vigenere
```

## Running the tests

* You can always look at the contents of message and encrypted message on terminal.  
* Change the message that you want to encrypt in **/test/test1.txt**.  
* You can have a look at the encrypted message in **/test/out1.txt**.  
* The **key** (a string) for vigenere is inserted manually via terminal.  

## Authors

* **Vitor G. Forbrig** - [Forbrig](https://github.com/Forbrig)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
