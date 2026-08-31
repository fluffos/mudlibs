$! BUILD.COM for Traceroute
$!
$ if f$trnlnm("MULTINET") .nes. "" then goto got_multinet
$ type sys$input

	Traceroute is a TCP/IP route path tracing utility.

	It requires the availability of the MultiNet TCP/IP for VMS
	product.  This product is available from Process Software, Inc.
	under separate license and fees.  Contact sales@aces.com or
	call 1-800-NAG-ACES for price quotes.

$exit
$nodir:
	
	Traceroute is a TCP/IP route path tracing utility

	Its build requires C include files normally installed as an
	optional part of the MultiNet installation.  These files would
	then reside in MULTINET_ROOT:[MULTINET.INCLUDE.*].

	Unfortunately these files are not present.  Please reinstall
	the MultiNet product to provide them and reattempt this build.

$exit

$got_multinet:
$ set noon
$sloop:
$ f=f$search("multinet_root:[multinet.include]*.dir")
$ if f .eqs. "" then goto end_sloop
$ g=f$element(1,"]",f)
$ g=f$element(0,".",g)
$ if f$trnlnm("''g'") .eqs. "" then -
  define 'g' multinet_root:[multinet.include.'g'],sys$share:
$ goto sloop
$end_sloop:
$ if "''p1'" .eqs. "LOGICALS" then $exit
$ if f$trnlnm("SYS") .eqs. "" then goto nodir
$ if f$trnlnm("ARPA") .eqs. "" then goto nodir
$ if f$trnlnm("NETINET") .eqs. "" then got nodir
$ if f$search("clis.h") .nes. "" 
$   then
$     cc_decc == "cc/decc/define=(""__vms"",""__decc"",""VMS_CLD"")/pref=ansi"
$     cc_vaxc   == "cc /define=(""__vms"",""VMS_CLD"")"
$   else
$     cc_decc == "cc/decc/define=(""__vms"",""__decc"")/pref=ansi"
$     cc_vaxc   == "cc /define=(""__vms"")"
$   endif
$ arch = f$getsyi("ARCH_NAME")
$ if f$search("sys$system:decc$compiler.exe") .nes. "" 
$   then
$     cc = cc_decc
$     optfile = "trace_decc.opt"
$   else
$     cc = cc_vaxc
$     optfile = "trace_vaxc.opt"
$   endif
$set ver
$ cc traceroute 
$ link/notrace traceroute,'optfile'/opt
$set nover
$ exit
