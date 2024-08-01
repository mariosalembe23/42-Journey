# MINITALK PROJECT

You must create a communication program in the form of a client and a server.
- The server must be started first. After its launch, it has to print its <strong>PID</strong>.
- The client takes two parameters:
- The server PID.
- The string to send.
- The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.
- The server has to display the string pretty quickly. Quickly means that if you think
it takes too long, then it is probably too long.
1 second for displaying 100 characters is way too much!
- Your server should be able to receive strings from several clients in a row without
needing to restart.
- The communication between your client and your server has to be done only using
UNIX signals.
- You can only use these two signals: SIGUSR1 and SIGUSR2.

<hr>

You should execute in the terminal the command ```make``` to generate de executables:
```ssh
make
```
### Running the server exec.
It will generate a ```server``` and ```client``` executable file, so, just to start de server:

```ssh
./server
```
### Send the signal (Message)
It will generate a PID: a positive number(PROCESS IDENTIFIER), so just send a signal with a message to this PID. You can do it that's form:

```ssh
./client <PID> [Message]
```
### Exemple

```ssh
./client 7788  "The server is running"
```
### Testing the program

You can to enter to ```tester``` directory and run the ```tester.sh``` or ```basic.sh``` file with the flag ```-m``` to mandatory part or ```-b``` to bonus part to test them.

```ssh
cd tester

./tester.sh 7788 -m

# OR

./basic.sh -m 7788
