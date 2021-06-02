# Student-Information-System

Projektni zadatak iz predmeta Objektno-Orijentisano programiranje (OOP) | 2 godina | zimski semestar

U ovom projektnom zadatku, bilo je potrebno napraviti funkcionalan program koji će moći riješiti probleme iz realnog života. Projektni zadatak će zahtjevati unos osnovnih podataka o studentu, kao što su ime, prezime, broj indeksa, godina studija i sl., te osnovnih podataka o predmetu kojeg spomenuti student polaže, kao što je naziv predmeta, te ostvareni uspjesi iz tog predmeta. Naš program neće biti ograničen na određeni skup predmeta, ili određenu godinu studija na fakultetu. Moći će se unositi studenti sa svake godine (1-5), kao i svi predmeti, koji će biti proizvoljni, što će omogućiti široku primjenu ovog programa. Naravno, u krajnjim ispisima jasno će se razlikovati studenti jedni od drugih. Bit će omogućen i ispis svih unijetih studenata što će omogućiti pregled cijele baze unesenih studenata na fakultetu. Pretraživanje unesenih studenata će se moći obavljati prema imenu, prezimenu, ostvarenim uspjesima, a također će biti omogućeno i pretraživanje predmeta po nazivu. Korisnik će moći jasno izabrati predmet za pretragu, na osnovu kojeg će dobiti razne informacije o studentu sa najviše i najmanje osvojenih bodova na datom predmetu, ispis studenata koji su položili taj predmet, ispih studenata koji nisu položili taj predmet, sortirani niz studenata po broju ostvarenih bodova na određenom predmetu i slično. Korisnik će također moći izbrisati studente iz baze, po svojoj volji. Birat će poziciju na kojoj se nalazi spomenuti student i bit će mu omogućeno brisanje istog. Program će postavljati jasna i koncizna ograničenja, kojih će se korisnik morati pridržavati ukoliko želi uspješno koristiti program. Naprimjer, korisnik će morati unijeti ograničen broj ukupnih bodova (100-120), od kojih 100 bodova predstavljaju dva parcijalna ispita.

Glavni meni Ponuđene su opcije:

Unesi stavke
Ispis ispita
Ispis položenih
Ispis nepoloženih
Prolaznost
Pretraga
Student s najmanjim brojem bodova
Student s najvećim brojem bodova
Izbriši studenta
Sortirani studenti po broju osvojenih bodova
Ispis studenata po godini studija
Kraj

Unošenjem broja neke opcije prikazuje se meni sa opcijama u kategoriji koju izabrali.

Unesi stavke Unosimo ime i prezime studenta, broj indexa, godinu studija, naziv predmeta, broj bodova koje nosi ispit, broj osvojenih bodova sa prve i druge parcijale

Ispis ispita Odabirom opcije ispis ispita ispisuju se informacije o svim ispitima i studentima koji su polagali ispite.

Ispis položenih Odabirom ove opcije unosimo predmet za pretragu. Nakon toga nam se ispisuju sve informacije vezane za predmet i za studente koji su polozili taj predmet. Ukoliko nema studentata koji su položili taj predmet onda se ispisuje da nema položenih ispita iz tog predmeta.

Ispis nepoloženih Odabirom ove opcije unosimo predmet za pretragu. Isto vrijedi kao i za “ispis položenih”. Ukoliko nema studenata koji nisu položili taj predmet onda će nam program ispisati da nema nepoloženih ispita iz tog predmeta.

Prolaznost Ukoliko izaberemo ovu opciju prvo unosimo predmet za pretragu. Nakon toga nam program izračuna i ispiše koliko prolaznost iz tog predmeta iznosi u postocima (%).

Pretraga Ponuđene su opcije:

Pretraga po imenu
Pretraga po prezimenu
Pretraga po nazivu predmeta
Vrati se Unošenjem broja neke opcije prikazuje se meni sa novim opcijama ili se izvršava tražena radnja.

Pretraga po imenu Ukoliko smo izabrali pretragu po imenu program će nam dati opciju da unesemo ime za pretragu i ispisat će sve studente koji imaju uneseno ime.

Pretraga po prezimenu Ukoliko smo izabrali pretragu po prezimenu program će nam dati opciju da unesemo prezime za pretragu i ispisat će sve studente koji imaju uneseno prezime.

Pretraga po nazivu predmeta Ukoliko smo izabrali pretragu po nazivu predmeta program će nam dati opciju da unesemo ime predmeta za pretragu i ispisat će sve studente koji pohađaju taj predmet.

Student s najmanjim brojem bodova Prvo unosimo predmet iz kojeg želimo saznati studenta s najmanjim brojem bodova. Program će izračunati koji od studenata ima najmanji broj bodova i ispisat će njegovo ime i prezime i broj osvojenih bodova.

Student s najvećim brojem bodova Prvo unosimo predmet iz kojeg želimo saznati studenta s najvecim brojem bodova. Program će izračunati koji od studenata ima najveći broj bodova i ispisat će njegovo ime i prezime i broj osvojenih bodova.

Izbriši studenta Ova opcija nam ispiše sve studente koji su unijeti u program i ponudi nam opciju da izaberemo redni broj studenta kojeg želimo obrisati.

Sortirani student po broju osvojenih bodova Prvo je potrebno da unesemo predmet iz kojeg želimo sortirani niz studenata. Program će ispisati studente od onog s najvećim brojem bodova do onog s najmanjim brojem bodova.

Ispis studenata po godini Prvo je potrebno da unesemo željenu godinu. Program će nakon toga ispisati sve studente koji se nalaze na toj godini, a ukoliko ih nema onda će ispisati da nema niko na toj godini.

Kraj Izlaz iz programa
