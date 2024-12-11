Hotellivarausjärjestelmä
Ohjelma on yksinkertainen hotellivarausjärjestelmä, joka mahdollistaa hotellihuoneiden
varaamisen, tehtyjen varausten tarkastelun ja päällekkäisten varausten eston.
Ohjelman toiminnot
Varauksen teko:
Käyttäjä syöttää varaajan nimen, valitsee huonenumeron (väliltä 1–100) ja määrittää öiden
määrän. Ohjelma tarkistaa, onko valittu huone jo varattu, ja estää päällekkäiset varaukset.
Lisäksi varmistetaan, että huonenumero ei ylity huoneiden määrästä. Varaus tallennetaan
onnistuneen tarkistuksen jälkeen.
Varausten haku:
Käyttäjä voi hakea varauksia syöttämällä varaajan nimen. Ohjelma näyttää kaikki kyseiselle
nimelle tehdyt varaukset, mukaan lukien varausnumeron, huonenumeron, öiden määrän ja
varauksen hinnan. Jos varauksia ei löydy, ohjelma ilmoittaa tästä selkeästi.
Päällekkäisten varausten esto:
Ennen uuden varauksen tekoa ohjelma tarkistaa, onko valittu huone jo varattu. Ohjelma käy läpi
kaikki varaukset vertaamalla huonenumeroita. Jos huone on varattu tai huonenumero ei vastaa
huoneiden lukumäärää, ohjelma pyytää valitsemaan toisen huoneen.
Rakenne:
Ohjelma tallentaa varaukset rakenteeseen (struct Varaus), joka sisältää varaajan nimen,
varausnumeron, huonenumeron ja öiden määrän. Kaikki varaukset tallennetaan vektoriin
(std::vector<Varaus>), joka mahdollistaa tietojen tarkastelun haussa.
Satunnaislukugeneraattori:
Jokaiselle varaukselle luodaan uniikki varausnumero satunnaislukugeneraattorilla.
Varausnumerot ovat välillä 10000–99999.
