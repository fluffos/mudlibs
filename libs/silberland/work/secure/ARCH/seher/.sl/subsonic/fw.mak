/def -p10 -mregexp -t'^Finsternis.$' finster = /repeat -0 1 schau
/def -p15 -mregexp -t'^Es ist zu dunkel !' dunkel = feuerwusel%;/repeat -01 1 schau%;
/def -p100 -t'*Nach oben geht es in die*' fangschlund = /edit -c0 finster%;/repeat 1 /edit -c100 finster
/def fwaus = /edit -c0 finster%;/edit -c0 dunkel%;/edit -c0 fangschlund
/def fwein = /edit -c100 finster%:/edit -c100 dunkel%;/edit -c100 fangschlund
