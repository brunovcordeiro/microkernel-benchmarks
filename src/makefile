#
# MIT License
#
# Copyright(c) 2011-2019 The Maintainers of Nanvix
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

#===============================================================================
# Generic Rules
#===============================================================================

# Builds Binary Files
all: all-apps all-buffer all-fork-join all-kcall-local all-kcall-remote all-noise \
		all-perf all-server all-comm all-teste

# Cleans Object Files
clean: clean-apps clean-buffer clean-fork-join clean-kcall-local clean-kcall-remote \
		clean-noise clean-perf clean-server clean-comm clean-teste

# Cleans Everything
distclean: distclean-apps distclean-buffer distclean-fork-join distclean-kcall-local \
		distclean-kcall-remote distclean-noise distclean-perf \
		distclean-server distclean-comm

# Builds multibinary images
image: image-apps image-buffer image-fork-join image-kcall-local image-kcall-remote \
		image-noise image-perf image-server image-comm

#===============================================================================
# apps
#===============================================================================

# Builds apps.
all-apps:
	@$(MAKE) -C apps all

# Cleans object files.
clean-apps:
	@$(MAKE) -C apps clean

# Cleans object files.
distclean-apps:
	@$(MAKE) -C apps distclean

# Builds multibinary image.
image-apps:
	@$(MAKE) -C apps image

#===============================================================================
# buffer
#===============================================================================

# Builds buffer.
all-buffer:
	@$(MAKE) -C buffer all

# Cleans object files.
clean-buffer:
	@$(MAKE) -C buffer clean

# Cleans object files.
distclean-buffer:
	@$(MAKE) -C buffer distclean

# Builds multibinary image.
image-buffer:
	@$(MAKE) -C buffer image

#===============================================================================
# fork-join
#===============================================================================

# Builds fork-join.
all-fork-join:
	@$(MAKE) -C fork-join all

# Cleans object files.
clean-fork-join:
	@$(MAKE) -C fork-join clean

# Cleans object files.
distclean-fork-join:
	@$(MAKE) -C fork-join distclean

# Builds multibinary image.
image-fork-join:
	@$(MAKE) -C fork-join image

#===============================================================================
# kcall-local
#===============================================================================

# Builds kcall-local.
all-kcall-local:
	@$(MAKE) -C kcall-local all

# Cleans object files.
clean-kcall-local:
	@$(MAKE) -C kcall-local clean

# Cleans object files.
distclean-kcall-local:
	@$(MAKE) -C kcall-local distclean

# Builds multibinary image.
image-kcall-local:
	@$(MAKE) -C kcall-local image

#===============================================================================
# kcall-remote
#===============================================================================

# Builds kcall-remote.
all-kcall-remote:
	@$(MAKE) -C kcall-remote all

# Cleans object files.
clean-kcall-remote:
	@$(MAKE) -C kcall-remote clean

# Cleans object files.
distclean-kcall-remote:
	@$(MAKE) -C kcall-remote distclean

# Builds multibinary image.
image-kcall-remote:
	@$(MAKE) -C kcall-remote image

#===============================================================================
# noise
#===============================================================================

# Builds noise.
all-noise:
	@$(MAKE) -C noise all

# Cleans object files.
clean-noise:
	@$(MAKE) -C noise clean

# Cleans object files.
distclean-noise:
	@$(MAKE) -C noise distclean

# Builds multibinary image.
image-noise:
	@$(MAKE) -C noise image

#===============================================================================
# perf
#===============================================================================

# Builds perf.
all-perf:
	@$(MAKE) -C perf all

# Cleans object files.
clean-perf:
	@$(MAKE) -C perf clean

# Cleans object files.
distclean-perf:
	@$(MAKE) -C perf distclean

# Builds multibinary image.
image-perf:
	@$(MAKE) -C perf image

#===============================================================================
# server
#===============================================================================

# Builds server.
all-server:
	@$(MAKE) -C server all

# Cleans object files.
clean-server:
	@$(MAKE) -C server clean

# Cleans object files.
distclean-server:
	@$(MAKE) -C server distclean

# Builds multibinary image.
image-server:
	@$(MAKE) -C server image

#===============================================================================
# upcall
#===============================================================================

# Builds upcall.
all-upcall:
	@$(MAKE) -C upcall all

# Cleans object files.
clean-upcall:
	@$(MAKE) -C upcall clean

# Cleans object files.
distclean-upcall:
	@$(MAKE) -C upcall distclean

# Builds multibinary image.
image-upcall:
	@$(MAKE) -C upcall image

#===============================================================================
# comm
#===============================================================================

# Builds comm.
all-comm:
	@$(MAKE) -C comm all

# Cleans object files.
clean-comm:
	@$(MAKE) -C comm clean

# Cleans object files.
distclean-comm:
	@$(MAKE) -C comm distclean

# Builds multibinary image.
image-comm:
	@$(MAKE) -C comm image

#===============================================================================
# comm
#===============================================================================

# Builds comm.
all-teste:
	@$(MAKE) -C teste all

# Cleans object files.
clean-teste:
	@$(MAKE) -C teste clean

# Cleans object files.
distclean-teste:
	@$(MAKE) -C teste distclean

# Builds multibinary image.
image-teste:
	@$(MAKE) -C teste image

