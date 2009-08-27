Bit.ly URL Shortening Plugin for Choqok
========================

This [bit.ly](http://bit.ly) plugin uses the plugin system in [Choqok](http://choqok.gnufolks.org/) and is based on the TightUrl plugin that comes with [Choqok](http://choqok.gnufolks.org/).

bit.ly
======

[bit.ly](http://bit.ly) is a URL shorting service. It allows people to take large URLs and shrink them for easier posting in places such as, but not limited to, places with limited text sizes.


Choqok
======

[Choqok](http://choqok.gnufolks.org/). is a KDE application that provides access to micro-blogging services like [Twitter](http://www.twitter.com) and [Identica](http://identi.ca)

To Use
======

* Get the [Choqok source](http://choqok.gnufolks.org/download/)
* Pull this source down
* Symlink this into the choqok/plugins/shorteners/ directory inside the Choqok source directory
* Add the line 'addSubdirectory(bitly)' to the choqok/plugins/shorteners/CMakeLists.txt file
* Follow the instructions in choqok/README to compile and install Choqok from source