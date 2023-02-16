################################################################################
#
# rtpmidid
#
################################################################################

RTPMIDID_VERSION = buildroot
RTPMIDID_SITE = git@github.com:dsokoloski/rtpmidid.git
RTPMIDID_SITE_METHOD=git
RTPMIDID_GIT_SUBMODULES = NO
RTPMIDID_LICENSE = GPL-2.1, GPL-3
RTPMIDID_LICENSE_FILES = LICENCE.md
RTPMIDID_CPE_ID_VENDOR = davidmoreno
RTPMIDID_CPE_ID_PRODUCT = rtpmidid
RTPMIDID_DEPENDENCIES = host-pkgconf host-automake host-autoconf host-libtool host-cmake zlib
RTPMIDID_INSTALL_STAGING = YES

$(eval $(cmake-package))
