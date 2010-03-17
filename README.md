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

* Get the source at: http://gitorious.org/~ncb000gt/choqok/ncb000gt-choqok
* Load the submodule for this.
* Follow the choqok build instructions.

Known Issues
============

* There is a problem where if you put a url in before specifying the API Login and API Key that it will use the "scraping" method rather than the API. I'm looking into it. To solve this, put your information in, save it, and then paste urls OR just restart the client.
* There is very little error handling. So, it's likely that the url shortening could have problems that aren't handled.