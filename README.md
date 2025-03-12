# 42solong
Projet du 3eme cercle du cursus 42

# Strategie
1. Parsing d'une map
2. Gestion des erreurs (map invalide)
3. Dessiner / trouver les sprites
4. Transformer les 1/0/e/p/c en images
5. Creer une nouvelle fenetre qui bouge pas si focus sur une autre / reduite
6. Afficher les images correctement (déplacements, collecte)
7. Implementer les inputs clavier avec affichage du nombre de mouvements dans terminal + fermeture correcte du programme
8. Implementer condition de victoire: parcourir la map pour savoir combien de collectibles, tant que pas tout ramasse sortie fermee, quand tout ramasse sortie ouverte.
9. Creer plusieurs maps fonctionnelles

# Parsing
Transformer la map en tableau de char: utiliser **get_next_line()** une premiere fois pour compter le nombre de lignes et allouer la taille du tableau, puis reutiliser **get_next_line()** pour allouer la taille de chaque ligne et les remplir avec **ft_strdup()**, en changeant les '\n' à la fin de chaque ligne en '\0'. Fermer le fichier a la fin des deux get_next_line(); faire les deux dans des fonctions differentes pour ne pas avoir besoin de fseek(), puisque pas autorise.

# Gestion des erreurs
Verifier si:
- le fichier existe
- le fichier est bien une map (.ber)
- la map n'est pas vide
- la map fait au minimum 3 lignes et 3 cases de largeur.
- la map ne contient que des 1, 0, P, C, E.
- la map est rectangulaire.
- la map est entouree de murs (1).
- la map est jouable:
  - la map a un seul joueur (P)
  - la map a une seule sortie (E)
  - la map a au moins 1 collectible (C)
  - chaque element est atteignable par le joueur (utiliser flood)

Faire des maps tests pour chaque erreur.

# Choisir les sprites
- Il faut un format divisible par 8 (16, 32, 64). 
- Le transparent n'est pas géré par la minilibx pour linux. On peut remplacer le transparent par la couleur de son choix, mais c'est tout. Oui, c'est moche.

# Implémenter la minilibx
- Sur linux: telecharger le fichier minilibx-linux.tgz.
- Extraire deux fois; copier/deplacer extrait dans les fichiers du projet, supprimer le git, gitignore, .git de la mini.
- Inclure la mlx dans le .h et le Makefile (attention, deux headers a inclure + des flags specifiques + d'abord compiler la mlx puis le projet)

# Créer une nouvelle fenêtre
- Créer une structure qui comportera toutes les variables que vous devrez passer dans l'essentiel des fonctions: un pointeur sur la mlx (ex. void * mlx_ptr), un pointeur sur la fenetre (ex. void *win_ptr), et toutes celles que vous estimerez necessaires.
- Faire une fonction qui appelle **mlx_init()** sur le mlx_ptr de la structure
- Puis qui appelle **mlx_new_window()** sur le win_ptr de la structure
- Puis qui appelle **mlx_loop()** sur le mlx_ptr de la structure pour faire tourner le programme à l'infini, jusqu'au exit().

# Poser les images
- Convertir les PNG en XPM via un site de conversion (https://to.imagestool.com/png-to-xpm), mettre les XPM dans les sources.
- Donner le chemin relatif des images à **mlx_xpm_file_to_imag()** pour les charger; stocker les adresses des images grace a la structure t_img de la mlx.
- Passer ces adresses à **mlx_put_image_to_window()** pour placer les images sur la fenêtre, en fonction de la map.

# Implémenter les inputs
Dans le header, définir les différents keycode linux qui nous intéressent pour le projet (A, W, S, D, Q, left arrow, up arrow, down arrow, right arrow, ESC).

Avant la mlx_loop(), appeler **mlx_hook()** deux fois, une première qui appelle **on_keypress()**, qu'il faudra définir soi-même ailleurs, une deuxième qui appelle **on_destroy()**, qu'il faudra également définir. Cela permet d'être prêt à recevoir des inputs à n'importe quel moment de la loop.

```
mlx_hook(your_game_struct.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &your_game_struct);
mlx_hook(your_game_struct.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &your_game_struct);
```

Définir **on_keypress()** : 
- Si keycode == K_A || K_AR_L : décaler joueur d'une case vers la gauche
- Si keycode == K_W || K_AR_U : décaler joueur d'une case vers le haut
- Si keycode == K_S || K_AR_D : décaler joueur d'une case vers le bas
- Si keycode == K_D || K_AR_R : décaler joueur d'une case vers la droite
- Si keycode == K_G || K_ESC : fermer le jeu (appeler on_destroy)

Définir **on_destroy()**:
- Utiliser **mlx_destroy_image()** pour détruire chaque image!! (éviter les still reachable)
- Utiliser **mlx_destroy_window()** pour détruire la fenêtre
- Utiliser **mlx_destroy_display()** pour détruire le contenu affiché dans la fenêtre
- Libérer la mémoire avec **free()** (ne rien oublier!! attention aux returns!!)
- Utiliser **exit()** pour fermer le programme correctement (sans cela, la loop segfault).

# Gérer les mouvements en bref
- Mettre à jour le tableau de la map, en déplaçant le P dans la nouvelle case et remettant l'ancien char dans la case précédente, une fois que le contenu de la nouvelle case a été analysée.
- Réafficher les images correspondantes.

## Mettre a jour les images
- Utiliser une structure pour gerer les positions (ex. t_pos: int x, int y): evite de recreer deux variables dans chaque fonction qui en a besoin et de devoir eventuellement les passer en arguments.
- Faire une fonction qui met a jour la case de depart et une autre qui met a jour la case d'arrivee

Dans mon projet, j'ai choisi de faire en sorte qu'un trou remplace les collectibles ramasses (des carottes), et qu'il reste meme si le joueur repasse dessus. A cause de cela, j'ai du implementer des conditions et donc des variables supplementaires. J'ai aussi choisi de pouvoir marcher sur la sortie (ne bloque pas le joueur).

**Case de depart**
- Verifier si la case de depart est un collectible ramasse (was_collectible == 1): si c'est le cas, on affiche l'image d'un collectible ramasse par-dessus celle du joueur, et on met a jour la map (map[x][y] = 'c').
- Sinon, verifier si la case de depart est la sortie (was_exit == 1): si c'est le cas, on affiche l'image de la sortie par-dessus celle du joueur, et on met a jour la map (map[x][y] = 'E').
- Sinon: on affiche l'image d'un sol simple par-dessus celle du joueur, et on met a jour la map (map[x][y] = 0).

**Case d'arrivee**
- On affiche l'image du joueur par-dessus celle de la case d'arrivee.
- Verifier si la case d'arrivee est un collectible (map[x][y] == 'C'): si c'est le cas, on decremente le nombre de collectible restants et on met a jour la map (map[x][y] = 'c').
- Verifier si la case d'arrivee est un collectible ramasse (map[x][y] == 'c'): si c'est le cas, on passe was_collectible a 1.
- Sinon, verifier si la case d'arrivee est la sortie (map[x][y] == 'E'): si c'est le cas,
  - verifier si tous les collectibles ont ete ramasses: si c'est le cas, on appele **on_destroy()**.
  - Sinon, on passe was_exit a 1.
- On met a jour la map (map[x][y] = 'P').
  
# Condition de victoire
- Au moment de la génération de la map, compter le nombre de collectibles: incrémenter une variable de la structure principale.
- Décrémenter celle-ci à chaque fois que la nouvelle case sur laquelle arrive le joueur contient un 'C'.
- Quand le joueur arrive sur la case de sortie, vérifier si la variable est à 0. Si oui, fermer le jeu: victoire! Sinon, quand le joueur quitte la case, y remettre une image de sortie.
