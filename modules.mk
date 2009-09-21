#
# $Id$
#
mod_rbl.la: mod_rbl.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_rbl.lo
DISTCLEAN_TARGETS = modules.mk
shared =  mod_rbl.la
