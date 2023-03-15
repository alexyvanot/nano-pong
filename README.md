# Nano Pong

---

## Installation

In order to use our project, make sure to import it in to Visual Studio Code with PlateformIO extension.

> 1. First, clone the project
> ```git clone git@gitlab.esiea.fr:vanot/nano-pong.git```
>
> 2. Then, import the project to VSCode using PlateformIO extension. Click on its icon at the side bar then pick the cloned git project.
>
> 3. 
>
>
>


## Consigne : *Exercice de fin.*

> #### Objectif: Faire un jeu de pong.
>
> - Le jeu doit être affiché sur la matrice de led.
> - Chaque raquette doit faire 3 pixels de large.
> - La balle doit faire 1 pixel de large.
> - Les contrôles de la raquette peuvent être (par joueur) : 2 boutons (haut/bas), 1 encoder ou 1 potentiomètre.
> - Le jeu doit pouvoir être lancé (il ne commence pas tout seul).
> - Quand une partie se termine, on doit pouvoir lancer une nouvelle partie sans reset.
> - Si la balle touche le bord haut de la raquette, elle doit partir à un angle de 45° vers le haut.
> - Si la balle touche le bord bas de la raquette, elle doit partir à un angle de 45° vers le bas.
> - Si la balle touche le centre de la raquette, elle doit repartir à l'horizontale.
> - Si la balle touche les bords haut et bas, elle doit rebondir.
> - Si la balle touche le bord droit ou gauche, le joueur adverse gagne un point.
> - Chaque joueur doit avoir 3 leds indiquant son nombre de points.
> - Le premier joueur à 3 points gagne le match.
> - Le jeu doit être fluide.