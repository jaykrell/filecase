__FILE__ is kinda not deterministic.
So it must be lowercased.
This repository demonstrates the problem.
It is a bit complicated.

You need to use -I.. and -Inot-.. and optionally
/FC for full paths.

What happens is that /FC uses the file system
to find the "correct" case, which can vary
from what you use with -I.

Then use __FILE__ in inline functions, in .h
files, that sometimes found with -I ..
sometimes found with -Inot-..

Two exes will be built using *almost* the same command lines,
and they will resolve __FILE__ to different case (lowercase vs. uppercase).

This makes hotpatch basically not deterministic.

To fix, we can lowercase all of our -I include paths, and remove -I .. everywhere,
or make all of our include paths match the file system. And/or only have actually
lowercase paths. Or maybe get a compiler change.
