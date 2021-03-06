include ../../config.mak
include config.mak
INSTALL = install

ifneq ($(targetos), Darwin)
NAME = libmelted++$(LIBSUF)
TARGET = $(NAME).$(version)
SONAME = $(NAME).$(soversion)
LIBFLAGS += -Wl,-soname,$(SONAME)
else
NAME = libmelted++$(LIBSUF)
TARGET = libmelted++.$(version)$(LIBSUF)
SONAME = libmelted++.$(soversion)$(LIBSUF)
LIBFLAGS += -install_name $(libdir)/$(SONAME) -current_version $(version) -compatibility_version $(soversion)
endif

CXXFLAGS += -I.. $(RDYNAMIC) -DVERSION=\"$(version)\"

LDFLAGS += -L../melted -lmelted -L../mvcp -lmvcp

OBJS = MltMelted.o \
	   MltResponse.o

SRCS = $(OBJS:.o=.cpp)
HEADERS = config.h $(OBJS:.o=.h)

all:		$(TARGET)

$(TARGET):	$(OBJS)
	$(CXX) $(LIBFLAGS) -o $@ $(OBJS) $(LDFLAGS)
	ln -sf $(TARGET) $(NAME)
	ln -sf $(TARGET) $(SONAME)

depend: $(SRCS)
	$(CXX) -MM $(CXXFLAGS) $^ 1>.depend

clean:
	$(RM) $(OBJS) $(TARGET) $(NAME) $(SONAME)

distclean:	clean

install:
	$(INSTALL) -d "$(DESTDIR)$(libdir)"
	$(INSTALL) -m 755 $(TARGET) $(DESTDIR)$(libdir)
	ln -sf $(TARGET) $(DESTDIR)$(libdir)/$(NAME)
	ln -sf $(TARGET) $(DESTDIR)$(libdir)/$(SONAME)
	$(INSTALL) -d "$(DESTDIR)$(prefix)/include/mlt/melted++"
	$(INSTALL) -m 644 $(HEADERS) "$(DESTDIR)$(prefix)/include/mlt/melted++"
	/sbin/ldconfig -n "$(DESTDIR)$(liobdir)" 2> /dev/null || true

uninstall:
	rm -f "$(DESTDIR)$(libdir)/$(TARGET)"
	rm -f "$(DESTDIR)$(libdir)/$(NAME)"
	rm -f "$(DESTDIR)$(libdir)/$(SONAME)"
	rm -rf "$(DESTDIR)$(prefix)/include/mlt/melted++"

ifneq ($(wildcard .depend),)
include .depend
endif
