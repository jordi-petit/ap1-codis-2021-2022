# Errors freqüents (del parcial del curs passat)

## Problema 1 (Dibuixar paràboles)

S'han penalitzat alguns aspectes de disseny (en general baixant 0.5 punts):

* Fer servir un `while` en bucles on es podia fer servir un `for` senzill

* Cridar a `pow(x,2)` per calcular `x*x`

* Excés de modularitat, per exemple dissenyar 4 funcions per un problema tant senzill.

* Considerar el cas `x=0` com a especial (no calia)

* Fer un bucle for per escriure `"----------"` (no calia)


## Problema 2 (Seqüències similars)

* Mirar si es pot llegir (`while (cin >> x and x != 0)` o variacions).
No cal en aquest problema.

* No estructurar gens el programa.

* Usar variables globals.


## Problema 3 (Base més petita amb el mateix nombre de dígits)

* Ignorar la pista: Calcular el nombre de dígits d'un nombre primer i
de l'altre després per acabar mirant si són iguals. Calia anar
comptant els dígits d'ambdós nombres alhora i parar
quan un d'ells ja no en tenia. Aquesta versió lenta s'ha puntuat
sobre 5.

* Intentar representar un nombre en base `b` en un enter enlloc
de comptar-li el seu nombre de dígits en base `b`.

* Inicialitzar variables que s'usen com a paràmetres reals de sortida
o no inicialitzar variables que s'usen com a paràmetres formals de sortida.

* Canviar l'especificació de la funció `base_amb_mateix_nombre_de_digits`.

* No declarar les variables tant tard com sigui possible.


## Problema 4 (Cercles fractals)

S'han detectat dos problemes fonamentals, que s'han penalitzat amb rigorositat:

* No dissenyar un esquema recursiu pel nivell `n` que inclogui 4 crides al nivell `n-1`.

* No propagar les coordenades a través de les crides recursives per ubicar els cercles correctament.
