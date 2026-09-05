# Sagenwelt Base-MudLib
## src/var/cfg

This directory contains basic confivuration files flr the MudLib.
These files are _NOT_ writeable from within the MudLib!

### directory structure

+   PRELOADS

    file containing objects to be preloaded at startup
    empty line or lines beginning with '#' are ignored
    lines ending in '/' contain directories and are searched for '*.c' files to
    be preloaded
