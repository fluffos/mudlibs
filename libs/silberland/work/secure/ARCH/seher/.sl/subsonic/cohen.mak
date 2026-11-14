/load gross.mak
/load sl.mak
/pre lpmp
/def -p10 -F -au -t'* teilt Dir mit: *' pingimmer = /beep
/def pingaus=/edit -c0 pingimmer
/def pingein=/edit -c100 pingimmer
/repeat 1 /echo hallo cohen!%;\
          /echo also es is folgendes:%;\
          /echo wenn dir wer was mitteilt machts beep!%;\
          /echo wennst das ausschalten willst tipp '/pingaus'%;\
          /echo wennst es wieder einschalten willst '/pingein'%;\
          /echo%;\
          /echo dobob - skripten leicht gemacht