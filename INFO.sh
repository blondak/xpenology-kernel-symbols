#!/bin/bash
# Copyright (c) 2000-2017 Synology Inc. All rights reserved.

source /pkgscripts-ng/include/pkg_util.sh

package="XpenologyKernelSymbols"
version="1.0.0-0001"
displayname="XpenologyKernelSymbols"
maintainer="Blonďák <blondak@neser.cz>"
arch="$(pkg_get_platform)"
description="This is a synology kernel module package."
[ "$(caller)" != "0 NULL" ] && return 0
pkg_dump_info
