# Basic Debian Packaging

This is intended to help in creating *very* basic Debian packages. It's only for
a package where you're simply copying files into place, but want to use a `.deb`.

If you want to compile something this, there are other better places to start.

## Using this framework

What gets installed is controlled by the `Makefile`.

    SRC_DIR=etc usr

 ...will install to this path on the target system.

    INSTALL_DIR=/

Example:

    SRC_DIR=foo
    INSTALL_DIR=/var/www

This will be installed to /var/www/foo

## Building

1. Use `debchange` to edit the `changelog`.
2. Run `fakeroot debian/rules binary`

