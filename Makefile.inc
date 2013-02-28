export PACKAGE=$(shell echo `egrep -i "^Package:" debian/control | cut -d ":" -f 2- | tr -d " "`)

all: Makefile $(SRC_DIR)

package:
	dpkg-buildpackage -b -rfakeroot

install:
	mkdir -p $(DESTDIR)$(INSTALL_DIR)/
	cp -r $(SRC_DIR) $(DESTDIR)$(INSTALL_DIR)/
	find $(DESTDIR)$(INSTALL_DIR)/ -type f -name .DS_Store -exec rm -f {} \;
	# find $(DESTDIR)$(INSTALL_DIR)/ -type d -name .svn -exec rm -rf {} \;

clean:
	rm -rf debian/$(PACKAGE)
	*stamp
