# Largest square

Programme trouvant le plus grand carré de '.' possible dans une carte composée de '.' et de 'o'

## Fonctionnement :


./square map

	  map : nom du fichier contenant la carte


## Générateur de plateau :


./gen_board.pl x y density

		x : largeur de la carte

		y : hauteur de la carte

		density : densité de 'o' dans la carte

## Exemple de carte :

10

.....o..o.

o.........

.....o.o..

...o......

.o........

o.........

..........

..........

.o..o.....

.o...oo...

## Résolution :

.....o..o.

o.........

.....o.o..

...oxxxxx.

.o..xxxxx.

o...xxxxx.

....xxxxx.

....xxxxx.

.o..o.....

.o...oo...
