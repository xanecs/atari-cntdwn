# Atari Mega ST New Year Countdown

![clock screen](https://raw.githubusercontent.com/xanecs/atari-cntdwn/master/doc/screen_clock.png)  
Fig. 1 *The clock screen of the countdown*

A countdown for the Atari Mega ST with TOS, written in modern C

## Preface

It has been a personal tradition of mine to write some sort of new year countdown application every year.
With this very simple application I try out different platforms and technologies.

Over the years, there have been Microsoft .NET Applications, Web sites, Something hacked together with VBA in Excel,
2 Android Apps (one with android Wear support), etc. But this year is something truly special.

A friend found an Atari Mega ST and after I read that it had a built in Real Time Clock, I just had to do it.
I knew it was not going to be easy, this is my first real C program after all.

![finish screen](https://raw.githubusercontent.com/xanecs/atari-cntdwn/master/doc/screen_finish.png)  
Fig. 2 *What you'll see when the new year has arrived*

## The Build system

As reference to myself and crazy minds trying to develop for the Atari alike, I am going to give a quick
rundown of the toolchain and build system this project is using.

It all starts with the awesome m68k-atari-mint cross-tools by
Vincent Rivière that can be found at http://vincent.riviere.free.fr/soft/m68k-atari-mint .

I have tried them on macOS, Fedora, Windows and Ubuntu, and would highly suggest using the Ubuntu version
as it seems to be very well maintained and worked flawlessly (as opposed ot the others).

Because of my lack of knowledge about the intricate detail of the gcc compiler flag system or make files
(remember, first C project) I could not figure out how to invoke the `m68k-atari-mint-gcc` compiler correctly
so that it would link against `GEMlib` (which handles all of the graphic functions).

I would therefore recommend using either Code::Blocks (if you don't experience the same crashes I do).
Just add a new toolchain, select the appropriate `m68k-atari-mint-xx` programs and add `-lgem` to the linker flags.

But because of said crashes I had to switch to the CMake system I am using now. Just take a peek at the
`CMakeLists.txt` in this repository, that should be pretty self explanatory.


## Reference Material for Aspiring Atari developers

Unfortunately there is very little detailed information about programming the Atari ST with C
on the internet. (Who would have guessed...)

But, there are some pretty comprehensive books out there that you can find in libraries
(Trust me, if they have a copy, it will be available). Of course you should adapt the examples in those books
to more modern C style. Use your intuition first (e.g. they often do some crazy preprocessor magic to define compiler
agnostic integer types, but we can use inttypes.h for this.) After that just try to get rid of the GCC warnings and
you should be good to go.

I have found the following to be very useful:

- Aumiller, Luda, Möllmann *Atari ST: GEM-Programmierung in C*. Markt&Technik, 1987 (German)
- *GEMLIB documentation.* http://arnaud.bercegeay.free.fr/gemlib/html/
- Wikipedia *Atari ST character set.* https://en.wikipedia.org/wiki/Atari_ST_character_set
