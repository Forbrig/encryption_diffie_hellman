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
* Breaker try to break the encrypted message written in **/test/out1.txt**.  
* You can change the words on **dictionary.dat**, the algorithm break the words by space.

### Breaker

* As known, trying to use brute force to find the key can be painful because (in our case, _256 ascii_) for each letter in the key length it add 256 possibilities. So if the key have 10 of length it must be between the 256^10 possibilities. With that in mind I've chose to try using the words on **dictionary.dat** as the key, and for each of these keys the algorithm breaks the decrypted message by spaces and compare if there is a word that match equaly in **dictionary.dat**. FOr each match it add a point, if in the end the key/decrypted message has a point it will be printed on the screen.

```c
point = 0;
token = strtok(sdecrypt, " "); //break the words where there are spaces
while (token != NULL) {
  for(j = 0; j < usable_size; j++) {
    if(strcmp(token, dictionary[j]) == 0) { //1 world match with dictionary
      point++;
    }
  }
  token = strtok(NULL, " ");
}
if (point > 0) {
printf("KEY:\n%s\nMESSAGE:\n%s\n", dictionary[i], aux_sdecrypt);
```

## Authors

* **Vitor G. Forbrig** - [Forbrig](https://github.com/Forbrig)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
