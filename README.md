# Basic Debian Packaging

This is intended to help in creating *very* basic Debian packages. It's only for
a package where you're simply copying files into place, but want to use a `.deb`.

If you want to compile something, there are other better places to start.

## Getting Started

* Run `mkdir src`.
* Place files into `src` as though it were the root directory.

### Package Metadata (Required)

To create the `changelog` run:

    debchange --create

Fill in the information about the package and save it.

Then edit the following files to describe your package.

* `debian/control` contains all package metadata.
* `debian/copyright` contains licensing information.

### Scripts (Optional)

Edit these scripts to perform actions at install and uninstall time.

* `debian/preinst` runs before package installation.
* `debian/postinst` runs after package installation.
* `debian/prerm` runs before package removal.
* `debian/postrm` runs after package removal.

## Building

1. Run `debchange -i` to update the `changelog` after each change.
2. Run `fakeroot debian/rules binary` to build your `.deb`.
