# Nano Pong

---

![Circuit](/resources/images/breadboard/t_main3.png "Circuit")
 ###### *Student project by Sandro Bakuradze ; Alexy Vanot ; Pierre Gervais ; Brice Nyamsi*

## **Usage and Rules**

Nano Pong is a two-dimensional sports game that simulates table tennis. The player controls an in-game paddle by moving it vertically across the left or right side of the screen.

They can compete against another player controlling a second paddle on the opposing side.
Players use the paddles to hit a ball back and forth.

**NOTE:** *This game runs on arduino nano chip.*

---

## **Images**

> There our breadboard. (develop in order to reveal)
- <div><details>
  <summary>Cliquez pour voir les images</summary>
  <img src="/resources/images/breadboard/main.jpg" alt="Circuit" title="Circuit">
  <img src="/resources/images/breadboard/main2.jpg" alt="Circuit" title="Circuit">
  <img src="/resources/images/breadboard/main3.jpg" alt="Circuit" title="Circuit">
  <img src="/resources/images/breadboard/MAX7219.jpg" alt="Circuit" title="Circuit">
  <img src="/resources/images/breadboard/nano.jpg" alt="Circuit" title="Circuit">
  <img src="/resources/images/breadboard/potentiometers.jpg" alt="Circuit" title="Circuit">
</details></div>


---

## **Installation**

In order to use our project, make sure to import it in to Visual Studio Code with PlateformIO extension.

> #### **1. Clone the repository**
>
> Execute this command into your terminal in order to clone this repository.
>
> ```git clone git@gitlab.esiea.fr:vanot/nano-pong.git```


> #### **2. Import the project**
> 
> Then, import the project to VSCode using PlateformIO extension. Click on its icon at the side bar then pick the cloned git project.
- <details>
  <summary>Cliquez pour voir les images</summary>
  <img src="/resources/images/read_me/init_platformio.png" alt="Init" title="Init">
  <img src="/resources/images/read_me/import_folder.png" alt="Pick" title="Pick">
</details>


> 
> #### **3. Plug the Arduino Nano to your computer** 
>
> Then upload on it the code then show its console.
- <details>
  <summary>Cliquez pour voir les images</summary>
  <img src="/resources/images/read_me/import.png" alt="Init" title="Init">
  <img src="/resources/images/read_me/serial_monitor.png" alt="Pick" title="Pick">
</details>


---

## **Consigne : *Exercice de fin.***

> #### **Objectif:** *Faire un jeu de pong.*
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
