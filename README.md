# c-testing
Random C and Assembly Testing

## tinyshell

This program outputs a prompt and runs whatever program is entered by the user. It is limited to a given number of characters. It exits back to the original shell with Ctrl-C, and could technically be run straight from Linux in something like an initramfs.

Lessons learned:
* cross-compiling can be a bit tedious, you have to go set up your stuff
  * I would prefer to use Linux directly in the future rather than Mac OS -> Linux
* you can re-create system calls (like read and write)
  * this makes the resulting binary a lot smaller
  * this is more work than using what's already there (e.g., you have to re-prototype)
  * your re-created system calls might behave differently than what you based them off
* if you re-create system calls and have name conflicts the linker might complain
  * make sure to get rid of anything like aliases that can confuse the linker about what you want
* you can break your program (possibly other things too) by putting more stuff in memory than what you ask the program to allocate
  * e.g. this program will start behaving weird if you give it more than 255 characters

Things I want to explore more:
* more ways assembly and C can play together
* figure out what the prototyping actually does under the hood
