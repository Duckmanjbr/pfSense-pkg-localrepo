# $FreeBSD$

PORTNAME=	pfSense-pkg-LocalRepo
PORTVERSION= 0.1
PORTREVISION= 1
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=
COMMENT=	Create local repositories on pfSense

LICENSE=	APACHE20

NO_BUILD=	yes
NO_MTREE=	yes

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	PORTNAME=${PORTNAME}

do-extract:
	${MKDIR} ${WRKSRC}

do-install:
	# {STAGEDIR}= /root/pfSense-pkg-localrepo/work/stage
	# {PREFIX}= /usr/local
	# {DATADIR}= /usr/local/share/pfSense-pkg-LocalRepo
	${MKDIR} ${STAGEDIR}${PREFIX}/pkg
	${MKDIR} ${STAGEDIR}${PREFIX}/bin/localrepo
	${MKDIR} ${STAGEDIR}/etc/inc/priv
	${MKDIR} ${STAGEDIR}/share/pfSense-pkg-LocalRepo
	${INSTALL_DATA} -m 0644 ${FILESDIR}${PREFIX}/pkg/localrepo.xml \
		${STAGEDIR}${PREFIX}/pkg
	${INSTALL_DATA} ${FILESDIR}${PREFIX}/pkg/localrepo.inc \
		${STAGEDIR}${PREFIX}/pkg
	${INSTALL_DATA} ${FILESDIR}${PREFIX}/bin/localrepo/localrepo.conf \
		${STAGEDIR}${PREFIX}/bin/localrepo
	${INSTALL_DATA} ${FILESDIR}/etc/inc/priv/localrepo.priv.inc \
		${STAGEDIR}/etc/inc/priv
	${INSTALL_DATA} ${FILESDIR}${DATADIR}/info.xml \
		${STAGEDIR}/share/pfSense-pkg-LocalRepo

post-build:
	@${REINPLACE_CMD} -i '' -e "s|%%PKGVERSION%%|${PKGVERSION}|" \
		${STAGEDIR}/share/pfSense-pkg-LocalRepo/info.xml

.include <bsd.port.mk>
