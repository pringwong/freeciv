# Makefile for PO directory in any package using GNU gettext.
# Copyright (C) 1995-2000 Ulrich Drepper <drepper@gnu.ai.mit.edu>
# Copyright (C) 2000-2020 Free Software Foundation, Inc.
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.
#
# Origin: gettext-0.21
GETTEXT_MACRO_VERSION = 0.20

PACKAGE = freeciv
VERSION = 3.2.91-dev
PACKAGE_BUGREPORT = https://osdn.net/projects/freeciv/ticket/

SED = /usr/bin/sed
SHELL = /bin/sh


srcdir = ../../../translations/nations
top_srcdir = ../../..
VPATH = ../../../translations/nations

prefix = /usr/local
exec_prefix = ${prefix}
datarootdir = ${prefix}/share
datadir = ${datarootdir}
localedir = ${datarootdir}/locale
gettextsrcdir = $(datadir)/gettext/po

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644

# We use $(mkdir_p).
# In automake <= 1.9.x, $(mkdir_p) is defined either as "mkdir -p --" or as
# "$(mkinstalldirs)" or as "$(install_sh) -d". For these automake versions,
# ${SHELL} /home/pring/freeciv-web/freeciv/freeciv/bootstrap/install-sh does not start with $(SHELL), so we add it.
# In automake >= 1.10, $(MKDIR_P) is derived from ${MKDIR_P}, which is defined
# either as "/path/to/mkdir -p" or ".../install-sh -c -d". For these automake
# versions, $(mkinstalldirs) and $(install_sh) are unused.
mkinstalldirs = $(SHELL) ${SHELL} /home/pring/freeciv-web/freeciv/freeciv/bootstrap/install-sh -d
install_sh = $(SHELL) ${SHELL} /home/pring/freeciv-web/freeciv/freeciv/bootstrap/install-sh
MKDIR_P = /usr/bin/mkdir -p
mkdir_p = $(MKDIR_P)

# When building gettext-tools, we prefer to use the built programs
# rather than installed programs.  However, we can't do that when we
# are cross compiling.
CROSS_COMPILING = @CROSS_COMPILING@

GMSGFMT_ = /usr/bin/msgfmt
GMSGFMT_no = /usr/bin/msgfmt
GMSGFMT_yes = /usr/bin/msgfmt
GMSGFMT = $(GMSGFMT_$(USE_MSGCTXT))
XGETTEXT_ = /usr/bin/xgettext
XGETTEXT_no = /usr/bin/xgettext
XGETTEXT_yes = /usr/bin/xgettext
XGETTEXT = $(XGETTEXT_$(USE_MSGCTXT))
MSGMERGE = /usr/bin/msgmerge
MSGMERGE_UPDATE = /usr/bin/msgmerge --update
MSGMERGE_FOR_MSGFMT_OPTION = --no-fuzzy-matching --no-location --quiet
MSGINIT = msginit
MSGCONV = msgconv
MSGFILTER = msgfilter

POFILES =  $(srcdir)/ar.po $(srcdir)/bg.po $(srcdir)/ca.po $(srcdir)/cs.po $(srcdir)/da.po $(srcdir)/de.po $(srcdir)/el.po $(srcdir)/en_GB.po $(srcdir)/eo.po $(srcdir)/es.po $(srcdir)/es_419.po $(srcdir)/et.po $(srcdir)/fa.po $(srcdir)/fi.po $(srcdir)/fr.po $(srcdir)/ga.po $(srcdir)/gd.po $(srcdir)/he.po $(srcdir)/hu.po $(srcdir)/id.po $(srcdir)/it.po $(srcdir)/ja.po $(srcdir)/ko.po $(srcdir)/lt.po $(srcdir)/nb.po $(srcdir)/nl.po $(srcdir)/pl.po $(srcdir)/pt_BR.po $(srcdir)/pt.po $(srcdir)/ro.po $(srcdir)/ru.po $(srcdir)/sr.po $(srcdir)/sv.po $(srcdir)/tr.po $(srcdir)/uk.po $(srcdir)/zh_CN.po $(srcdir)/zh_TW.po
GMOFILES =  $(srcdir)/ar.gmo $(srcdir)/bg.gmo $(srcdir)/ca.gmo $(srcdir)/cs.gmo $(srcdir)/da.gmo $(srcdir)/de.gmo $(srcdir)/el.gmo $(srcdir)/en_GB.gmo $(srcdir)/eo.gmo $(srcdir)/es.gmo $(srcdir)/es_419.gmo $(srcdir)/et.gmo $(srcdir)/fa.gmo $(srcdir)/fi.gmo $(srcdir)/fr.gmo $(srcdir)/ga.gmo $(srcdir)/gd.gmo $(srcdir)/he.gmo $(srcdir)/hu.gmo $(srcdir)/id.gmo $(srcdir)/it.gmo $(srcdir)/ja.gmo $(srcdir)/ko.gmo $(srcdir)/lt.gmo $(srcdir)/nb.gmo $(srcdir)/nl.gmo $(srcdir)/pl.gmo $(srcdir)/pt_BR.gmo $(srcdir)/pt.gmo $(srcdir)/ro.gmo $(srcdir)/ru.gmo $(srcdir)/sr.gmo $(srcdir)/sv.gmo $(srcdir)/tr.gmo $(srcdir)/uk.gmo $(srcdir)/zh_CN.gmo $(srcdir)/zh_TW.gmo
UPDATEPOFILES =  ar.po-update bg.po-update ca.po-update cs.po-update da.po-update de.po-update el.po-update en_GB.po-update eo.po-update es.po-update es_419.po-update et.po-update fa.po-update fi.po-update fr.po-update ga.po-update gd.po-update he.po-update hu.po-update id.po-update it.po-update ja.po-update ko.po-update lt.po-update nb.po-update nl.po-update pl.po-update pt_BR.po-update pt.po-update ro.po-update ru.po-update sr.po-update sv.po-update tr.po-update uk.po-update zh_CN.po-update zh_TW.po-update
DUMMYPOFILES =  ar.nop bg.nop ca.nop cs.nop da.nop de.nop el.nop en_GB.nop eo.nop es.nop es_419.nop et.nop fa.nop fi.nop fr.nop ga.nop gd.nop he.nop hu.nop id.nop it.nop ja.nop ko.nop lt.nop nb.nop nl.nop pl.nop pt_BR.nop pt.nop ro.nop ru.nop sr.nop sv.nop tr.nop uk.nop zh_CN.nop zh_TW.nop
DISTFILES.common = Makefile.in.in remove-potcdate.sin \
$(DISTFILES.common.extra1) $(DISTFILES.common.extra2) $(DISTFILES.common.extra3)
DISTFILES = $(DISTFILES.common) Makevars POTFILES.in meson.build \
$(POFILES) $(GMOFILES) \
$(DISTFILES.extra1) $(DISTFILES.extra2) $(DISTFILES.extra3)

POTFILES = \
     ../../../data/nation/abkhaz.ruleset \
     ../../../data/nation/aborigines.ruleset \
     ../../../data/nation/abyssinian.ruleset \
     ../../../data/nation/acadian.ruleset \
     ../../../data/nation/acehnese.ruleset \
     ../../../data/nation/acrean.ruleset \
     ../../../data/nation/afghani.ruleset \
     ../../../data/nation/african.ruleset \
     ../../../data/nation/ainu.ruleset \
     ../../../data/nation/akwe.ruleset \
     ../../../data/nation/alandalus.ruleset \
     ../../../data/nation/alander.ruleset \
     ../../../data/nation/albanian.ruleset \
     ../../../data/nation/aleut.ruleset \
     ../../../data/nation/algerian.ruleset \
     ../../../data/nation/alsatian.ruleset \
     ../../../data/nation/amazigh.ruleset \
     ../../../data/nation/amazonian.ruleset \
     ../../../data/nation/andorran.ruleset \
     ../../../data/nation/angolan.ruleset \
     ../../../data/nation/anhaltian.ruleset \
     ../../../data/nation/anishinaabe.ruleset \
     ../../../data/nation/antarctican.ruleset \
     ../../../data/nation/antiguan.ruleset \
     ../../../data/nation/antillean.ruleset \
     ../../../data/nation/aragonese.ruleset \
     ../../../data/nation/aramean.ruleset \
     ../../../data/nation/argentine.ruleset \
     ../../../data/nation/armenian.ruleset \
     ../../../data/nation/ashanti.ruleset \
     ../../../data/nation/assamese.ruleset \
     ../../../data/nation/assyrian.ruleset \
     ../../../data/nation/asturian.ruleset \
     ../../../data/nation/atlantean.ruleset \
     ../../../data/nation/australian.ruleset \
     ../../../data/nation/avar.ruleset \
     ../../../data/nation/aymara.ruleset \
     ../../../data/nation/azeri.ruleset \
     ../../../data/nation/badian.ruleset \
     ../../../data/nation/bahamian.ruleset \
     ../../../data/nation/bahraini.ruleset \
     ../../../data/nation/bangladeshi.ruleset \
     ../../../data/nation/barbadian.ruleset \
     ../../../data/nation/bashkir.ruleset \
     ../../../data/nation/basque.ruleset \
     ../../../data/nation/bavarian.ruleset \
     ../../../data/nation/belarusian.ruleset \
     ../../../data/nation/belgian.ruleset \
     ../../../data/nation/belgic.ruleset \
     ../../../data/nation/belizean.ruleset \
     ../../../data/nation/bengali.ruleset \
     ../../../data/nation/beninese.ruleset \
     ../../../data/nation/benin.ruleset \
     ../../../data/nation/bhutanese.ruleset \
     ../../../data/nation/biafran.ruleset \
     ../../../data/nation/bissauguinean.ruleset \
     ../../../data/nation/boer.ruleset \
     ../../../data/nation/boian.ruleset \
     ../../../data/nation/bolivian.ruleset \
     ../../../data/nation/bosnia.ruleset \
     ../../../data/nation/bosporan.ruleset \
     ../../../data/nation/botswanan.ruleset \
     ../../../data/nation/brandenburgian.ruleset \
     ../../../data/nation/breton.ruleset \
     ../../../data/nation/british.ruleset \
     ../../../data/nation/briton.ruleset \
     ../../../data/nation/bruneian.ruleset \
     ../../../data/nation/bulgarian.ruleset \
     ../../../data/nation/burgundian.ruleset \
     ../../../data/nation/burgundic.ruleset \
     ../../../data/nation/burkinabe.ruleset \
     ../../../data/nation/burmese.ruleset \
     ../../../data/nation/burundi.ruleset \
     ../../../data/nation/buryat.ruleset \
     ../../../data/nation/californian.ruleset \
     ../../../data/nation/cambodian.ruleset \
     ../../../data/nation/cameroonian.ruleset \
     ../../../data/nation/canadian.ruleset \
     ../../../data/nation/canari.ruleset \
     ../../../data/nation/cantonese.ruleset \
     ../../../data/nation/capeverdean.ruleset \
     ../../../data/nation/carantanian.ruleset \
     ../../../data/nation/castilian.ruleset \
     ../../../data/nation/catalan.ruleset \
     ../../../data/nation/celtiberian.ruleset \
     ../../../data/nation/centralafrican.ruleset \
     ../../../data/nation/centralamerican.ruleset \
     ../../../data/nation/centrallithuanian.ruleset \
     ../../../data/nation/chadian.ruleset \
     ../../../data/nation/cham.ruleset \
     ../../../data/nation/chananean.ruleset \
     ../../../data/nation/chechen.ruleset \
     ../../../data/nation/chiapanec.ruleset \
     ../../../data/nation/chickasaw.ruleset \
     ../../../data/nation/chilean.ruleset \
     ../../../data/nation/chimu.ruleset \
     ../../../data/nation/chinook.ruleset \
     ../../../data/nation/choctaw.ruleset \
     ../../../data/nation/chola.ruleset \
     ../../../data/nation/chrobatian.ruleset \
     ../../../data/nation/chumash.ruleset \
     ../../../data/nation/chuvash.ruleset \
     ../../../data/nation/circassian.ruleset \
     ../../../data/nation/colombian.ruleset \
     ../../../data/nation/comanche.ruleset \
     ../../../data/nation/comorian.ruleset \
     ../../../data/nation/confederate.ruleset \
     ../../../data/nation/congolesebrazzaville.ruleset \
     ../../../data/nation/congolese.ruleset \
     ../../../data/nation/cornish.ruleset \
     ../../../data/nation/corsican.ruleset \
     ../../../data/nation/cossack.ruleset \
     ../../../data/nation/costarican.ruleset \
     ../../../data/nation/cree.ruleset \
     ../../../data/nation/cretan.ruleset \
     ../../../data/nation/crimeantatar.ruleset \
     ../../../data/nation/croatian.ruleset \
     ../../../data/nation/crusader.ruleset \
     ../../../data/nation/cuban.ruleset \
     ../../../data/nation/curonian.ruleset \
     ../../../data/nation/cuyavian.ruleset \
     ../../../data/nation/cypriot.ruleset \
     ../../../data/nation/cyrenaican.ruleset \
     ../../../data/nation/czechoslovak.ruleset \
     ../../../data/nation/czech.ruleset \
     ../../../data/nation/dacian.ruleset \
     ../../../data/nation/dahomean.ruleset \
     ../../../data/nation/darfuri.ruleset \
     ../../../data/nation/djiboutian.ruleset \
     ../../../data/nation/dominicano.ruleset \
     ../../../data/nation/dominican.ruleset \
     ../../../data/nation/dryad.ruleset \
     ../../../data/nation/eastgerman.ruleset \
     ../../../data/nation/easttimorese.ruleset \
     ../../../data/nation/ecuadorian.ruleset \
     ../../../data/nation/egyptianarab.ruleset \
     ../../../data/nation/elamite.ruleset \
     ../../../data/nation/emirati.ruleset \
     ../../../data/nation/epirote.ruleset \
     ../../../data/nation/equatoguinean.ruleset \
     ../../../data/nation/eritrean.ruleset \
     ../../../data/nation/esperant.ruleset \
     ../../../data/nation/estonian.ruleset \
     ../../../data/nation/etruscan.ruleset \
     ../../../data/nation/european.ruleset \
     ../../../data/nation/evenki.ruleset \
     ../../../data/nation/faroese.ruleset \
     ../../../data/nation/fijian.ruleset \
     ../../../data/nation/filipino.ruleset \
     ../../../data/nation/finnish.ruleset \
     ../../../data/nation/flemish.ruleset \
     ../../../data/nation/florentine.ruleset \
     ../../../data/nation/florida.ruleset \
     ../../../data/nation/formosan.ruleset \
     ../../../data/nation/franconian.ruleset \
     ../../../data/nation/frankish.ruleset \
     ../../../data/nation/frisian.ruleset \
     ../../../data/nation/friulian.ruleset \
     ../../../data/nation/fulani.ruleset \
     ../../../data/nation/gabonese.ruleset \
     ../../../data/nation/gaelic.ruleset \
     ../../../data/nation/galician.ruleset \
     ../../../data/nation/gallic.ruleset \
     ../../../data/nation/gambian.ruleset \
     ../../../data/nation/genoese.ruleset \
     ../../../data/nation/georgian.ruleset \
     ../../../data/nation/gepid.ruleset \
     ../../../data/nation/germanbelgian.ruleset \
     ../../../data/nation/germanic.ruleset \
     ../../../data/nation/ghanaian.ruleset \
     ../../../data/nation/ghana.ruleset \
     ../../../data/nation/ghaznavid.ruleset \
     ../../../data/nation/gokturk.ruleset \
     ../../../data/nation/goldenhorde.ruleset \
     ../../../data/nation/gothic.ruleset \
     ../../../data/nation/greaterpolish.ruleset \
     ../../../data/nation/greenlander.ruleset \
     ../../../data/nation/grenadian.ruleset \
     ../../../data/nation/guanche.ruleset \
     ../../../data/nation/guarani.ruleset \
     ../../../data/nation/guatemalan.ruleset \
     ../../../data/nation/guinean.ruleset \
     ../../../data/nation/gupta.ruleset \
     ../../../data/nation/guyanese.ruleset \
     ../../../data/nation/hacker.ruleset \
     ../../../data/nation/haitian.ruleset \
     ../../../data/nation/hanoverian.ruleset \
     ../../../data/nation/han.ruleset \
     ../../../data/nation/hansa.ruleset \
     ../../../data/nation/hasinay.ruleset \
     ../../../data/nation/hawaiian.ruleset \
     ../../../data/nation/hellenic.ruleset \
     ../../../data/nation/helvetian.ruleset \
     ../../../data/nation/hephthalite.ruleset \
     ../../../data/nation/hessian.ruleset \
     ../../../data/nation/himyarite.ruleset \
     ../../../data/nation/holyroman.ruleset \
     ../../../data/nation/holysee.ruleset \
     ../../../data/nation/honduran.ruleset \
     ../../../data/nation/hopi.ruleset \
     ../../../data/nation/hungarian.ruleset \
     ../../../data/nation/iberian.ruleset \
     ../../../data/nation/icelandic.ruleset \
     ../../../data/nation/illyrian.ruleset \
     ../../../data/nation/indoeuropean.ruleset \
     ../../../data/nation/inuit.ruleset \
     ../../../data/nation/iranian.ruleset \
     ../../../data/nation/iraqi.ruleset \
     ../../../data/nation/irish.ruleset \
     ../../../data/nation/israeli.ruleset \
     ../../../data/nation/israelite.ruleset \
     ../../../data/nation/italiangreek.ruleset \
     ../../../data/nation/ivoirian.ruleset \
     ../../../data/nation/jaffna.ruleset \
     ../../../data/nation/jamaican.ruleset \
     ../../../data/nation/jolof.ruleset \
     ../../../data/nation/jordanian.ruleset \
     ../../../data/nation/kalmyk.ruleset \
     ../../../data/nation/kanem-bornu.ruleset \
     ../../../data/nation/karabakhi.ruleset \
     ../../../data/nation/karelian.ruleset \
     ../../../data/nation/karen.ruleset \
     ../../../data/nation/kashmiri.ruleset \
     ../../../data/nation/kashubian.ruleset \
     ../../../data/nation/katangan.ruleset \
     ../../../data/nation/kazakh.ruleset \
     ../../../data/nation/kenyan.ruleset \
     ../../../data/nation/khazar.ruleset \
     ../../../data/nation/khoisan.ruleset \
     ../../../data/nation/khwarezmian.ruleset \
     ../../../data/nation/kiribati.ruleset \
     ../../../data/nation/kittitian.ruleset \
     ../../../data/nation/komi.ruleset \
     ../../../data/nation/kongo.ruleset \
     ../../../data/nation/kosovar.ruleset \
     ../../../data/nation/kuna.ruleset \
     ../../../data/nation/kurd.ruleset \
     ../../../data/nation/kushan.ruleset \
     ../../../data/nation/kuwaiti.ruleset \
     ../../../data/nation/kyrgyz.ruleset \
     ../../../data/nation/langobardic.ruleset \
     ../../../data/nation/lankese.ruleset \
     ../../../data/nation/laotian.ruleset \
     ../../../data/nation/latin.ruleset \
     ../../../data/nation/latvian.ruleset \
     ../../../data/nation/lebanese.ruleset \
     ../../../data/nation/lendian.ruleset \
     ../../../data/nation/leonese.ruleset \
     ../../../data/nation/lesothoan.ruleset \
     ../../../data/nation/liberian.ruleset \
     ../../../data/nation/liburnian.ruleset \
     ../../../data/nation/libyan.ruleset \
     ../../../data/nation/liechtensteiner.ruleset \
     ../../../data/nation/liege.ruleset \
     ../../../data/nation/ligurian.ruleset \
     ../../../data/nation/lipkatatar.ruleset \
     ../../../data/nation/lippe.ruleset \
     ../../../data/nation/lithuanian.ruleset \
     ../../../data/nation/lojbanistani.ruleset \
     ../../../data/nation/lorrain.ruleset \
     ../../../data/nation/luwian.ruleset \
     ../../../data/nation/luxembourgish.ruleset \
     ../../../data/nation/lycian.ruleset \
     ../../../data/nation/maasai.ruleset \
     ../../../data/nation/macedonian.ruleset \
     ../../../data/nation/macedon.ruleset \
     ../../../data/nation/majapahit.ruleset \
     ../../../data/nation/malagasy.ruleset \
     ../../../data/nation/malawian.ruleset \
     ../../../data/nation/malaysian.ruleset \
     ../../../data/nation/maldivian.ruleset \
     ../../../data/nation/malian.ruleset \
     ../../../data/nation/maltese.ruleset \
     ../../../data/nation/mamluk.ruleset \
     ../../../data/nation/manchu.ruleset \
     ../../../data/nation/manx.ruleset \
     ../../../data/nation/maori.ruleset \
     ../../../data/nation/mapuche.ruleset \
     ../../../data/nation/marathi.ruleset \
     ../../../data/nation/marshallese.ruleset \
     ../../../data/nation/martian.ruleset \
     ../../../data/nation/mauritanian.ruleset \
     ../../../data/nation/mauritian.ruleset \
     ../../../data/nation/mazovian.ruleset \
     ../../../data/nation/mecklenburgian.ruleset \
     ../../../data/nation/median.ruleset \
     ../../../data/nation/messapian.ruleset \
     ../../../data/nation/metis.ruleset \
     ../../../data/nation/mexican.ruleset \
     ../../../data/nation/miao.ruleset \
     ../../../data/nation/micronesian.ruleset \
     ../../../data/nation/mikmaq.ruleset \
     ../../../data/nation/milanese.ruleset \
     ../../../data/nation/miskito.ruleset \
     ../../../data/nation/mitanni.ruleset \
     ../../../data/nation/mixtec.ruleset \
     ../../../data/nation/moldovan.ruleset \
     ../../../data/nation/moluccan.ruleset \
     ../../../data/nation/monegasque.ruleset \
     ../../../data/nation/mon.ruleset \
     ../../../data/nation/montenegrin.ruleset \
     ../../../data/nation/moravian.ruleset \
     ../../../data/nation/mordvin.ruleset \
     ../../../data/nation/moroccan.ruleset \
     ../../../data/nation/mozambican.ruleset \
     ../../../data/nation/mughal.ruleset \
     ../../../data/nation/muscovite.ruleset \
     ../../../data/nation/muskogee.ruleset \
     ../../../data/nation/mwiska.ruleset \
     ../../../data/nation/namibian.ruleset \
     ../../../data/nation/nauruan.ruleset \
     ../../../data/nation/navajo.ruleset \
     ../../../data/nation/neapolitan.ruleset \
     ../../../data/nation/nenets.ruleset \
     ../../../data/nation/nepali.ruleset \
     ../../../data/nation/nestorian.ruleset \
     ../../../data/nation/newfoundland.ruleset \
     ../../../data/nation/newzealand.ruleset \
     ../../../data/nation/nicaraguan.ruleset \
     ../../../data/nation/nigerian.ruleset \
     ../../../data/nation/nigerien.ruleset \
     ../../../data/nation/nimiipuu.ruleset \
     ../../../data/nation/norman.ruleset \
     ../../../data/nation/northkorean.ruleset \
     ../../../data/nation/northumbrian.ruleset \
     ../../../data/nation/norwegian.ruleset \
     ../../../data/nation/novgorodian.ruleset \
     ../../../data/nation/nubian.ruleset \
     ../../../data/nation/numidian.ruleset \
     ../../../data/nation/nuu-chah-nulth.ruleset \
     ../../../data/nation/occitan.ruleset \
     ../../../data/nation/ohlone.ruleset \
     ../../../data/nation/oldenburgian.ruleset \
     ../../../data/nation/oldprussian.ruleset \
     ../../../data/nation/omani.ruleset \
     ../../../data/nation/ossetian.ruleset \
     ../../../data/nation/ostrogothic.ruleset \
     ../../../data/nation/otomi.ruleset \
     ../../../data/nation/ottoman.ruleset \
     ../../../data/nation/ozite.ruleset \
     ../../../data/nation/paeonian.ruleset \
     ../../../data/nation/pakistani.ruleset \
     ../../../data/nation/palatinate.ruleset \
     ../../../data/nation/palauan.ruleset \
     ../../../data/nation/palestinian.ruleset \
     ../../../data/nation/palmyrene.ruleset \
     ../../../data/nation/panamanian.ruleset \
     ../../../data/nation/papuanewguinean.ruleset \
     ../../../data/nation/papuan.ruleset \
     ../../../data/nation/paraguayan.ruleset \
     ../../../data/nation/parthian.ruleset \
     ../../../data/nation/pashtun.ruleset \
     ../../../data/nation/pelasgian.ruleset \
     ../../../data/nation/peruvian.ruleset \
     ../../../data/nation/phoenician.ruleset \
     ../../../data/nation/phrygian.ruleset \
     ../../../data/nation/pictish.ruleset \
     ../../../data/nation/piedmontese.ruleset \
     ../../../data/nation/pontic.ruleset \
     ../../../data/nation/prussian.ruleset \
     ../../../data/nation/puertorican.ruleset \
     ../../../data/nation/purhepecha.ruleset \
     ../../../data/nation/qatari.ruleset \
     ../../../data/nation/quebecois.ruleset \
     ../../../data/nation/rapanui.ruleset \
     ../../../data/nation/raramuri.ruleset \
     ../../../data/nation/rhenish.ruleset \
     ../../../data/nation/riffian.ruleset \
     ../../../data/nation/riograndense.ruleset \
     ../../../data/nation/romanian.ruleset \
     ../../../data/nation/romansh.ruleset \
     ../../../data/nation/rusyn.ruleset \
     ../../../data/nation/ruthenian.ruleset \
     ../../../data/nation/rwandan.ruleset \
     ../../../data/nation/ryukyuan.ruleset \
     ../../../data/nation/sabine.ruleset \
     ../../../data/nation/sahrawi.ruleset \
     ../../../data/nation/saintlucian.ruleset \
     ../../../data/nation/saka.ruleset \
     ../../../data/nation/salishan.ruleset \
     ../../../data/nation/salvadoran.ruleset \
     ../../../data/nation/sami.ruleset \
     ../../../data/nation/sammarinese.ruleset \
     ../../../data/nation/samnite.ruleset \
     ../../../data/nation/samoan.ruleset \
     ../../../data/nation/samogitian.ruleset \
     ../../../data/nation/santomean.ruleset \
     ../../../data/nation/sardinian.ruleset \
     ../../../data/nation/sarmatian.ruleset \
     ../../../data/nation/saudi.ruleset \
     ../../../data/nation/savoyard.ruleset \
     ../../../data/nation/saxon.ruleset \
     ../../../data/nation/scanian.ruleset \
     ../../../data/nation/schleswig-holsteinian.ruleset \
     ../../../data/nation/scottishgaelic.ruleset \
     ../../../data/nation/scottish.ruleset \
     ../../../data/nation/scythian.ruleset \
     ../../../data/nation/seleucid.ruleset \
     ../../../data/nation/seljuk.ruleset \
     ../../../data/nation/seminole.ruleset \
     ../../../data/nation/senegalese.ruleset \
     ../../../data/nation/serbian.ruleset \
     ../../../data/nation/seychellois.ruleset \
     ../../../data/nation/shan.ruleset \
     ../../../data/nation/shawnee.ruleset \
     ../../../data/nation/sherpa.ruleset \
     ../../../data/nation/siberian.ruleset \
     ../../../data/nation/sicilian.ruleset \
     ../../../data/nation/sierraleonean.ruleset \
     ../../../data/nation/sikh.ruleset \
     ../../../data/nation/sikkimese.ruleset \
     ../../../data/nation/silesian.ruleset \
     ../../../data/nation/singaporean.ruleset \
     ../../../data/nation/sinhalese.ruleset \
     ../../../data/nation/slavic.ruleset \
     ../../../data/nation/slovakian.ruleset \
     ../../../data/nation/slovenian.ruleset \
     ../../../data/nation/solomonislander.ruleset \
     ../../../data/nation/somaliland.ruleset \
     ../../../data/nation/somali.ruleset \
     ../../../data/nation/sorbian.ruleset \
     ../../../data/nation/sotho.ruleset \
     ../../../data/nation/southafrican.ruleset \
     ../../../data/nation/southamerican.ruleset \
     ../../../data/nation/southkorean.ruleset \
     ../../../data/nation/southsudanese.ruleset \
     ../../../data/nation/southvietnamese.ruleset \
     ../../../data/nation/southyemeni.ruleset \
     ../../../data/nation/soviet.ruleset \
     ../../../data/nation/srivijaya.ruleset \
     ../../../data/nation/sudanese.ruleset \
     ../../../data/nation/suebian.ruleset \
     ../../../data/nation/surinamese.ruleset \
     ../../../data/nation/swahili.ruleset \
     ../../../data/nation/swazi.ruleset \
     ../../../data/nation/swiss.ruleset \
     ../../../data/nation/syrian.ruleset \
     ../../../data/nation/tahitian.ruleset \
     ../../../data/nation/tairona.ruleset \
     ../../../data/nation/taiwanese.ruleset \
     ../../../data/nation/tajik.ruleset \
     ../../../data/nation/tanganyikan.ruleset \
     ../../../data/nation/tanzanian.ruleset \
     ../../../data/nation/tatar.ruleset \
     ../../../data/nation/templar.ruleset \
     ../../../data/nation/teutonic.ruleset \
     ../../../data/nation/texan.ruleset \
     ../../../data/nation/thracian.ruleset \
     ../../../data/nation/thuringian.ruleset \
     ../../../data/nation/tibetan.ruleset \
     ../../../data/nation/timurid.ruleset \
     ../../../data/nation/tocharian.ruleset \
     ../../../data/nation/togolese.ruleset \
     ../../../data/nation/toltec.ruleset \
     ../../../data/nation/tongan.ruleset \
     ../../../data/nation/transnistrian.ruleset \
     ../../../data/nation/transylvanian.ruleset \
     ../../../data/nation/trinidadian.ruleset \
     ../../../data/nation/tswana.ruleset \
     ../../../data/nation/tuareg.ruleset \
     ../../../data/nation/tunisian.ruleset \
     ../../../data/nation/turkishcypriot.ruleset \
     ../../../data/nation/turkmen.ruleset \
     ../../../data/nation/tuvan.ruleset \
     ../../../data/nation/tyrolian.ruleset \
     ../../../data/nation/ugandan.ruleset \
     ../../../data/nation/ukrainian.ruleset \
     ../../../data/nation/un.ruleset \
     ../../../data/nation/urartian.ruleset \
     ../../../data/nation/uruguayan.ruleset \
     ../../../data/nation/uyghur.ruleset \
     ../../../data/nation/uzbek.ruleset \
     ../../../data/nation/vampire.ruleset \
     ../../../data/nation/vandalic.ruleset \
     ../../../data/nation/vanuatuan.ruleset \
     ../../../data/nation/vedic.ruleset \
     ../../../data/nation/veletian.ruleset \
     ../../../data/nation/venda.ruleset \
     ../../../data/nation/venetian.ruleset \
     ../../../data/nation/venetic.ruleset \
     ../../../data/nation/venezuelan.ruleset \
     ../../../data/nation/vermont.ruleset \
     ../../../data/nation/vietnamese.ruleset \
     ../../../data/nation/vincentian.ruleset \
     ../../../data/nation/visigothic.ruleset \
     ../../../data/nation/vistulan.ruleset \
     ../../../data/nation/volapuk.ruleset \
     ../../../data/nation/volgabulgar.ruleset \
     ../../../data/nation/volgagerman.ruleset \
     ../../../data/nation/walloon.ruleset \
     ../../../data/nation/welsh.ruleset \
     ../../../data/nation/werewolf.ruleset \
     ../../../data/nation/westernpomeranian.ruleset \
     ../../../data/nation/westernroman.ruleset \
     ../../../data/nation/westindian.ruleset \
     ../../../data/nation/westphalian.ruleset \
     ../../../data/nation/wuerttembergian.ruleset \
     ../../../data/nation/xhosa.ruleset \
     ../../../data/nation/xiongnu.ruleset \
     ../../../data/nation/yakut.ruleset \
     ../../../data/nation/yemeni.ruleset \
     ../../../data/nation/yucatecan.ruleset \
     ../../../data/nation/yugoslav.ruleset \
     ../../../data/nation/zambian.ruleset \
     ../../../data/nation/zanzibari.ruleset \
     ../../../data/nation/zapotec.ruleset \
     ../../../data/nation/zhuang.ruleset \
     ../../../data/nation/zimbabwean.ruleset

CATALOGS =  ar.gmo bg.gmo ca.gmo cs.gmo da.gmo de.gmo el.gmo en_GB.gmo eo.gmo es.gmo es_419.gmo et.gmo fa.gmo fi.gmo fr.gmo ga.gmo gd.gmo he.gmo hu.gmo id.gmo it.gmo ja.gmo ko.gmo lt.gmo nb.gmo nl.gmo pl.gmo pt_BR.gmo pt.gmo ro.gmo ru.gmo sr.gmo sv.gmo tr.gmo uk.gmo zh_CN.gmo zh_TW.gmo

POFILESDEPS_ = $(srcdir)/$(DOMAIN).pot
POFILESDEPS_yes = $(POFILESDEPS_)
POFILESDEPS_no =
POFILESDEPS = $(POFILESDEPS_$(PO_DEPENDS_ON_POT))

DISTFILESDEPS_ = update-po
DISTFILESDEPS_yes = $(DISTFILESDEPS_)
DISTFILESDEPS_no =
DISTFILESDEPS = $(DISTFILESDEPS_$(DIST_DEPENDS_ON_UPDATE_PO))

# Makevars gets inserted here. (Don't remove this line!)
# Makefile variables for PO directory in any package using GNU gettext.

# Usually the message domain is the same as the package name.
DOMAIN = freeciv-nations

# These two variables depend on the location of this directory.
subdir = translations/nations
top_builddir = ../..

# These options get passed to xgettext.
XGETTEXT_OPTIONS = \
  --keyword=_ --flag=_:1:pass-c-format \
  --keyword=N_ --flag=N_:1:pass-c-format \
  --flag=error:3:c-format --flag=error_at_line:5:c-format \
  --flag=asprintf:2:c-format --flag=vasprintf:2:c-format \
  --flag=xasprintf:1:c-format --flag=error_logger:1:c-format \
  --flag=po_error:3:c-format --flag=po_error_at_line:5:c-format \
  --flag=po_gram_error:1:c-format --flag=po_gram_error_at_line:2:c-format

# This is the copyright holder that gets inserted into the header of the
# $(DOMAIN).pot file.  Set this to the copyright holder of the surrounding
# package.  (Note that the msgstr strings, extracted from the package's
# sources, belong to the copyright holder of the package.)  Translators are
# expected to transfer the copyright for their translations to this person
# or entity, or to disclaim their copyright.  The empty string stands for
# the public domain; in this case the translators are expected to disclaim
# their copyright.
COPYRIGHT_HOLDER = Freeciv Project

# This tells whether or not to prepend "GNU " prefix to the package
# name that gets inserted into the header of the $(DOMAIN).pot file.
# Possible values are "yes", "no", or empty.  If it is empty, try to
# detect it automatically by scanning the files in $(top_srcdir) for
# "GNU packagename" string.
PACKAGE_GNU =

# This is the email address or URL to which the translators shall report
# bugs in the untranslated strings:
# - Strings which are not entire sentences, see the maintainer guidelines
#   in the GNU gettext documentation, section 'Preparing Strings'.
# - Strings which use unclear terms or require additional context to be
#   understood.
# - Strings which make invalid assumptions about notation of date, time or
#   money.
# - Pluralisation problems.
# - Incorrect English spelling.
# - Incorrect formatting.
# It can be your email address, or a mailing list address where translators
# can write to without being subscribed, or the URL of a web page through
# which the translators can contact you.
MSGID_BUGS_ADDRESS =

# This is the list of locale categories, beyond LC_MESSAGES, for which the
# message catalogs shall be used.  It is usually empty.
EXTRA_LOCALE_CATEGORIES =

# This tells whether the $(DOMAIN).pot file contains messages with an 'msgctxt'
# context.  Possible values are "yes" and "no".  Set this to yes if the
# package uses functions taking also a message context, like pgettext(), or
# if in $(XGETTEXT_OPTIONS) you define keywords with a context argument.
USE_MSGCTXT = yes

# These options get passed to msgmerge.
# Useful options are in particular:
#   --previous            to keep previous msgids of translated messages,
#   --quiet               to reduce the verbosity.
MSGMERGE_OPTIONS = --previous --quiet

# These options get passed to msginit.
# If you want to disable line wrapping when writing PO files, add
# --no-wrap to MSGMERGE_OPTIONS, XGETTEXT_OPTIONS, and
# MSGINIT_OPTIONS.
MSGINIT_OPTIONS =

# This tells whether or not to regenerate a PO file when $(DOMAIN).pot
# has changed.  Possible values are "yes" and "no".  Set this to no if
# the POT file is checked in the repository and the version control
# program ignores timestamps.
PO_DEPENDS_ON_POT = no

# This tells whether or not to forcibly update $(DOMAIN).pot and
# regenerate PO files on "make dist".  Possible values are "yes" and
# "no".  Set this to no if the POT file and PO files are maintained
# externally.
DIST_DEPENDS_ON_UPDATE_PO = yes

all: all-yes


.SUFFIXES:
.SUFFIXES: .po .gmo .sed .sin .nop .po-create .po-update

# The .pot file, stamp-po, .po files, and .gmo files appear in release tarballs.
# The GNU Coding Standards say in
# <https://www.gnu.org/prep/standards/html_node/Makefile-Basics.html>:
#   "GNU distributions usually contain some files which are not source files
#    ... . Since these files normally appear in the source directory, they
#    should always appear in the source directory, not in the build directory.
#    So Makefile rules to update them should put the updated files in the
#    source directory."
# Therefore we put these files in the source directory, not the build directory.

# During .po -> .gmo conversion, take into account the most recent changes to
# the .pot file. This eliminates the need to update the .po files when the
# .pot file has changed, which would be troublesome if the .po files are put
# under version control.
$(GMOFILES): $(srcdir)/$(DOMAIN).pot
.po.gmo:
	@lang=`echo $* | sed -e 's,.*/,,'`; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}rm -f $${lang}.gmo && $(MSGMERGE) $(MSGMERGE_FOR_MSGFMT_OPTION) -o $${lang}.1po $${lang}.po $(DOMAIN).pot && $(GMSGFMT) -c --statistics --verbose -o $${lang}.gmo $${lang}.1po && rm -f $${lang}.1po"; \
	cd $(srcdir) && \
	rm -f $${lang}.gmo && \
	$(MSGMERGE) $(MSGMERGE_FOR_MSGFMT_OPTION) -o $${lang}.1po $${lang}.po $(DOMAIN).pot && \
	$(GMSGFMT) -c --statistics --verbose -o t-$${lang}.gmo $${lang}.1po && \
	mv t-$${lang}.gmo $${lang}.gmo && \
	rm -f $${lang}.1po

.sin.sed:
	sed -e '/^#/d' $< > t-$@
	mv t-$@ $@


all-yes: $(srcdir)/stamp-po
all-no:

# Ensure that the gettext macros and this Makefile.in.in are in sync.
CHECK_MACRO_VERSION = \
	test "$(GETTEXT_MACRO_VERSION)" = "0.20" \
	  || { echo "*** error: gettext infrastructure mismatch: using a Makefile.in.in from gettext version $(GETTEXT_MACRO_VERSION) but the autoconf macros are from gettext version 0.20" 1>&2; \
	       exit 1; \
	     }

# $(srcdir)/$(DOMAIN).pot is only created when needed. When xgettext finds no
# internationalized messages, no $(srcdir)/$(DOMAIN).pot is created (because
# we don't want to bother translators with empty POT files). We assume that
# LINGUAS is empty in this case, i.e. $(POFILES) and $(GMOFILES) are empty.
# In this case, $(srcdir)/stamp-po is a nop (i.e. a phony target).

# $(srcdir)/stamp-po is a timestamp denoting the last time at which the CATALOGS
# have been loosely updated. Its purpose is that when a developer or translator
# checks out the package from a version control system, and the $(DOMAIN).pot
# file is not under version control, "make" will update the $(DOMAIN).pot and
# the $(CATALOGS), but subsequent invocations of "make" will do nothing. This
# timestamp would not be necessary if updating the $(CATALOGS) would always
# touch them; however, the rule for $(POFILES) has been designed to not touch
# files that don't need to be changed.
$(srcdir)/stamp-po: $(srcdir)/$(DOMAIN).pot
	@$(CHECK_MACRO_VERSION)
	test ! -f $(srcdir)/$(DOMAIN).pot || \
	  test -z "$(GMOFILES)" || $(MAKE) $(GMOFILES)
	@test ! -f $(srcdir)/$(DOMAIN).pot || { \
	  echo "touch $(srcdir)/stamp-po" && \
	  echo timestamp > $(srcdir)/stamp-poT && \
	  mv $(srcdir)/stamp-poT $(srcdir)/stamp-po; \
	}

# Note: Target 'all' must not depend on target '$(DOMAIN).pot-update',
# otherwise packages like GCC can not be built if only parts of the source
# have been downloaded.

# This target rebuilds $(DOMAIN).pot; it is an expensive operation.
# Note that $(DOMAIN).pot is not touched if it doesn't need to be changed.
# The determination of whether the package xyz is a GNU one is based on the
# heuristic whether some file in the top level directory mentions "GNU xyz".
# If GNU 'find' is available, we avoid grepping through monster files.
$(DOMAIN).pot-update: $(POTFILES) $(srcdir)/POTFILES.in remove-potcdate.sed
	package_gnu="$(PACKAGE_GNU)"; \
	test -n "$$package_gnu" || { \
	  if { if (LC_ALL=C find --version) 2>/dev/null | grep GNU >/dev/null; then \
	         LC_ALL=C find -L $(top_srcdir) -maxdepth 1 -type f -size -10000000c -exec grep -i 'GNU freeciv' /dev/null '{}' ';' 2>/dev/null; \
	       else \
	         LC_ALL=C grep -i 'GNU freeciv' $(top_srcdir)/* 2>/dev/null; \
	       fi; \
	     } | grep -v 'libtool:' >/dev/null; then \
	     package_gnu=yes; \
	   else \
	     package_gnu=no; \
	   fi; \
	}; \
	if test "$$package_gnu" = "yes"; then \
	  package_prefix='GNU '; \
	else \
	  package_prefix=''; \
	fi; \
	if test -n '$(MSGID_BUGS_ADDRESS)' || test '$(PACKAGE_BUGREPORT)' = '@'PACKAGE_BUGREPORT'@'; then \
	  msgid_bugs_address='$(MSGID_BUGS_ADDRESS)'; \
	else \
	  msgid_bugs_address='$(PACKAGE_BUGREPORT)'; \
	fi; \
	case `$(XGETTEXT) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	  '' | 0.[0-9] | 0.[0-9].* | 0.1[0-5] | 0.1[0-5].* | 0.16 | 0.16.[0-1]*) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	      $(XGETTEXT_OPTIONS)  --keyword=Q_ --keyword=PL_:1,2 --language=C --escape --add-comments=TRANS: --from-code=UTF-8 \
	    ;; \
	  *) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --package-name="$${package_prefix}freeciv" \
	      --package-version='3.2.91-dev' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	      $(XGETTEXT_OPTIONS)  --keyword=Q_ --keyword=PL_:1,2 --language=C --escape --add-comments=TRANS: --from-code=UTF-8 \
	    ;; \
	esac
	test ! -f $(DOMAIN).po || { \
	  if test -f $(srcdir)/$(DOMAIN).pot-header; then \
	    sed -e '1,/^#$$/d' < $(DOMAIN).po > $(DOMAIN).1po && \
	    cat $(srcdir)/$(DOMAIN).pot-header $(DOMAIN).1po > $(DOMAIN).po && \
	    rm -f $(DOMAIN).1po \
	    || exit 1; \
	  fi; \
	  if test -f $(srcdir)/$(DOMAIN).pot; then \
	    sed -f remove-potcdate.sed < $(srcdir)/$(DOMAIN).pot > $(DOMAIN).1po && \
	    sed -f remove-potcdate.sed < $(DOMAIN).po > $(DOMAIN).2po && \
	    if cmp $(DOMAIN).1po $(DOMAIN).2po >/dev/null 2>&1; then \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(DOMAIN).po; \
	    else \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(srcdir)/$(DOMAIN).pot && \
	      mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	    fi; \
	  else \
	    mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	  fi; \
	}

# This rule has no dependencies: we don't need to update $(DOMAIN).pot at
# every "make" invocation, only create it when it is missing.
# Only "make $(DOMAIN).pot-update" or "make dist" will force an update.
$(srcdir)/$(DOMAIN).pot:
	$(MAKE) $(DOMAIN).pot-update

# This target rebuilds a PO file if $(DOMAIN).pot has changed.
# Note that a PO file is not touched if it doesn't need to be changed.
$(POFILES): $(POFILESDEPS)
	@test -f $(srcdir)/$(DOMAIN).pot || $(MAKE) $(srcdir)/$(DOMAIN).pot
	@lang=`echo $@ | sed -e 's,.*/,,' -e 's/\.po$$//'`; \
	if test -f "$(srcdir)/$${lang}.po"; then \
	  test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	  echo "$${cdcmd}$(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} --previous $${lang}.po $(DOMAIN).pot"; \
	  cd $(srcdir) \
	    && { case `$(MSGMERGE_UPDATE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	           '' | 0.[0-9] | 0.[0-9].* | 0.1[0-5] | 0.1[0-5].*) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) $${lang}.po $(DOMAIN).pot;; \
	           0.1[6-7] | 0.1[6-7].*) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --previous $${lang}.po $(DOMAIN).pot;; \
	           *) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} --previous $${lang}.po $(DOMAIN).pot;; \
	         esac; \
	       }; \
	else \
	  $(MAKE) $${lang}.po-create; \
	fi


install: install-exec install-data
install-exec:
install-data: install-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    $(INSTALL_DATA) $(srcdir)/$$file \
			    $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	  for file in Makevars; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
install-data-no: all
install-data-yes: all
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  if test -r $$cat; then realcat=$$cat; else realcat=$(srcdir)/$$cat; fi; \
	  $(INSTALL_DATA) $$realcat $(DESTDIR)$$dir/$(DOMAIN).mo; \
	  echo "installing $$realcat as $(DESTDIR)$$dir/$(DOMAIN).mo"; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	      rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      ln -s ../LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      ln $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      cp -p $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      echo "installing $$realcat link as $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo"; \
	    fi; \
	  done; \
	done

install-strip: install

installdirs: installdirs-exec installdirs-data
installdirs-exec:
installdirs-data: installdirs-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	else \
	  : ; \
	fi
installdirs-data-no:
installdirs-data-yes:
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	    fi; \
	  done; \
	done

# Define this as empty until I found a useful application.
installcheck:

uninstall: uninstall-exec uninstall-data
uninstall-exec:
uninstall-data: uninstall-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
uninstall-data-no:
uninstall-data-yes:
	catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  for lc in LC_MESSAGES $(EXTRA_LOCALE_CATEGORIES); do \
	    rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	  done; \
	done

check: all

info dvi ps pdf html tags TAGS ctags CTAGS ID:

install-dvi install-ps install-pdf install-html:

mostlyclean:
	rm -f remove-potcdate.sed
	rm -f $(srcdir)/stamp-poT
	rm -f core core.* $(DOMAIN).po $(DOMAIN).1po $(DOMAIN).2po *.new.po
	rm -fr *.o

clean: mostlyclean

distclean: clean
	rm -f Makefile Makefile.in POTFILES

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f $(srcdir)/$(DOMAIN).pot $(srcdir)/stamp-po $(GMOFILES)

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir:
	test -z "$(DISTFILESDEPS)" || $(MAKE) $(DISTFILESDEPS)
	@$(MAKE) dist2
# This is a separate target because 'update-po' must be executed before.
dist2: $(srcdir)/stamp-po $(DISTFILES)
	@dists="$(DISTFILES)"; \
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  dists="$$dists Makevars.template"; \
	fi; \
	if test -f $(srcdir)/$(DOMAIN).pot; then \
	  dists="$$dists $(DOMAIN).pot stamp-po"; \
	else \
	  case $(XGETTEXT) in \
	    :) echo "Warning: Creating a tarball without '$(DOMAIN).pot', because a suitable 'xgettext' program was not found in PATH." 1>&2;; \
	    *) echo "Warning: Creating a tarball without '$(DOMAIN).pot', because 'xgettext' found no strings to extract. Check the contents of the POTFILES.in file and the XGETTEXT_OPTIONS in the Makevars file." 1>&2;; \
	  esac; \
	fi; \
	if test -f $(srcdir)/ChangeLog; then \
	  dists="$$dists ChangeLog"; \
	fi; \
	for i in 0 1 2 3 4 5 6 7 8 9; do \
	  if test -f $(srcdir)/ChangeLog.$$i; then \
	    dists="$$dists ChangeLog.$$i"; \
	  fi; \
	done; \
	if test -f $(srcdir)/LINGUAS; then dists="$$dists LINGUAS"; fi; \
	for file in $$dists; do \
	  if test -f $$file; then \
	    cp -p $$file $(distdir) || exit 1; \
	  else \
	    cp -p $(srcdir)/$$file $(distdir) || exit 1; \
	  fi; \
	done

update-po: Makefile
	$(MAKE) $(DOMAIN).pot-update
	test -z "$(UPDATEPOFILES)" || $(MAKE) $(UPDATEPOFILES)
	$(MAKE) update-gmo

# General rule for creating PO files.

.nop.po-create:
	@lang=`echo $@ | sed -e 's/\.po-create$$//'`; \
	echo "File $$lang.po does not exist. If you are a translator, you can create it through 'msginit'." 1>&2; \
	exit 1

# General rule for updating PO files.

.nop.po-update:
	@lang=`echo $@ | sed -e 's/\.po-update$$//'`; \
	if test "$(PACKAGE)" = "gettext-tools" && test "$(CROSS_COMPILING)" != "yes"; then PATH=`pwd`/../src:$$PATH; fi; \
	tmpdir=`pwd`; \
	echo "$$lang:"; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}$(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang --previous $$lang.po $(DOMAIN).pot -o $$lang.new.po"; \
	cd $(srcdir); \
	if { case `$(MSGMERGE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	       '' | 0.[0-9] | 0.[0-9].* | 0.1[0-5] | 0.1[0-5].*) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	       0.1[6-7] | 0.1[6-7].*) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) --previous -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	       *) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang --previous -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	     esac; \
	   }; then \
	  if cmp $$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	    rm -f $$tmpdir/$$lang.new.po; \
	  else \
	    if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	      :; \
	    else \
	      echo "msgmerge for $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	      exit 1; \
	    fi; \
	  fi; \
	else \
	  echo "msgmerge for $$lang.po failed!" 1>&2; \
	  rm -f $$tmpdir/$$lang.new.po; \
	fi

$(DUMMYPOFILES):

update-gmo: Makefile $(GMOFILES)
	@:

# Recreate Makefile by invoking config.status. Explicitly invoke the shell,
# because execution permission bits may not work on the current file system.
# Use /bin/bash, which is the shell determined by autoconf for the use by its
# scripts, not $(SHELL) which is hardwired to /bin/sh and may be deficient.
Makefile: Makefile.in.in Makevars $(top_builddir)/config.status POTFILES.in LINGUAS
	cd $(top_builddir) \
	  && /bin/bash ./config.status $(subdir)/$@.in po-directories

force:

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
