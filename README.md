Projet du 3ème cercle du cursus 42

# Stratégie
1. Parsing d'une map
2. Gestion des erreurs (map invalide)
3. Dessiner / trouver les sprites
4. Transformer les 1/0/e/p/c en images
5. Créer une nouvelle fenêtre qui bouge pas si focus sur une autre / réduite
6. Afficher les images correctement (déplacements, collecte)
7. Implémenter les inputs clavier avec affichage du nombre de mouvements dans terminal + fermeture correcte du programme
8. Implémenter condition de victoire: parcourir la map pour savoir combien de collectibles, tant que pas tout ramassé sortie fermée, quand tout ramassé sortie ouverte.
9. Créer plusieurs maps fonctionnelles

**Remarque**: j'ai du utiliser **ft_calloc()** au lieu de **malloc()** pour faire taire un warning de Valgrind. Il estimait que certaines variables pouvaient, en cas d'erreur, ne pas être initialisées, ce qui peut mener à des resultats inattendus car une variable non initialisée va prendre la valeur qu'elle trouve par défaut dans la mémoire.

# Parsing
Transformer la map en tableau de char: utiliser **get_next_line()** une première fois pour compter le nombre de lignes et allouer la taille du tableau, puis réutiliser **get_next_line()** pour allouer la taille de chaque ligne et les remplir avec **ft_strdup()**, en changeant les '\n' à la fin de chaque ligne en '\0'. Fermer le fichier à la fin des deux get_next_line(); faire les deux dans des fonctions différentes pour ne pas avoir besoin de fseek(), puisque pas autorisé.

# Gestion des erreurs
Vérifier si:
- le fichier existe (éviter les segfault!)
- le fichier est bien une map (.ber)
- la map n'est pas vide (éviter les segfault!)
- la map fait au minimum 3 lignes et 3 cases de largeur.
- la map ne contient que des 1, 0, P, C, E.
- la map est rectangulaire.
- la map est entourée de murs (1).
- la map est jouable:
  - la map a un seul joueur (P)
  - la map a une seule sortie (E)
  - la map a au moins 1 collectible (C)
  - chaque élément est atteignable par le joueur (utiliser flood)

Faire des maps tests pour chaque erreur.

# Choisir les sprites
- Il faut un format divisible par 8 (16, 32, 64). 
- Le transparent n'est pas géré par la minilibx pour linux. On peut remplacer le transparent par la couleur de son choix, mais c'est tout. Oui, c'est moche.

# Implémenter la minilibx
- Sur linux: télécharger le fichier minilibx-linux.tgz.
- Extraire deux fois; copier/déplacer extrait dans les fichiers du projet, supprimer le git, gitignore, .git de la mini.
- Inclure la mlx dans le .h et le Makefile (attention, deux headers à inclure + des flags spécifiques + d'abord compiler la mlx puis le projet)

# Créer une nouvelle fenêtre
- Créer une structure qui comportera toutes les variables que vous devrez passer dans l'essentiel des fonctions: un pointeur sur la mlx (ex. void * mlx_ptr), un pointeur sur la fenêtre (ex. void *win_ptr), et toutes celles que vous estimerez necessaires.
- Faire une fonction qui appelle **mlx_init()** sur le mlx_ptr de la structure pour initialiser la mlx.
- Puis qui appelle **mlx_new_window()** sur le win_ptr de la structure pour créer la nouvelle fenêtre. 
- Puis qui appelle **mlx_loop()** sur le mlx_ptr de la structure pour faire tourner le programme à l'infini, jusqu'au exit().

La taille de la fenêtre = la taille de votre map, soit pour la hauteur le nombre de lignes * la hauteur d'une de vos tuiles et pour la largeur le nombre de colonnes * la largeur d'une de vos tuiles. 

# Poser les images
- Convertir les PNG en XPM via un site de conversion (https://to.imagestool.com/png-to-xpm), mettre les XPM dans les sources.
- Donner le chemin relatif des images à **mlx_xpm_file_to_imag()** pour les charger; stocker les adresses des images grâce à la structure t_img de la mlx.
- Passer ces adresses à **mlx_put_image_to_window()** pour placer les tuiles sur la fenêtre, en fonction de la map.

**Remarque:** personnellement, j'ai du inverser les axes x et y au moment d'afficher les tuiles en fonction de la map.

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

# Gérer les mouvements
- Mettre à jour le tableau de la map, en déplaçant le P dans la nouvelle case et remettant l'ancien char dans la case précédente, une fois que le contenu de la nouvelle case a été analysée.
- Réafficher les images correspondantes.
- Incrémenter le nombre de mouvement et l'afficher dans le terminal / sur la fenêtre.

## Mettre à jour les images et la map
- Utiliser une structure pour gérer les positions (ex. t_pos: int x, int y): évite de recréer deux variables dans chaque fonction qui en a besoin et de devoir éventuellement les passer en arguments.
- Faire une fonction qui met à jour la case de départ et une autre qui met à jour la case d'arrivée

Dans mon projet, j'ai choisi de faire en sorte qu'un trou remplace les collectibles ramassés (des carottes), et qu'il reste même si le joueur repasse dessus. A cause de cela, j'ai du implémenter des conditions et donc des variables supplémentaires. J'ai aussi choisi de pouvoir marcher sur la sortie (ne bloque pas le joueur). Enfin, j'ai choisi de faire des pseudo-animations, en faisant tourner en boucle plusieurs frames pour chaque direction prise par le joueur.

**Case de départ**
- Vérifier si la case de départ est un collectible ramassé (was_collectible == 1): si c'est le cas, on repasse was_collectible à 0, on affiche l'image d'un collectible ramassé par-dessus celle du joueur, et on met à jour la map (map[x][y] = 'c').
- Sinon, vérifier si la case de départ est la sortie (was_exit == 1): si c'est le cas, on repasse was_exit à 0, on affiche l'image de la sortie par-dessus celle du joueur, et on met à jour la map (map[x][y] = 'E').
- Sinon: on affiche l'image d'un sol simple par-dessus celle du joueur, et on met à jour la map (map[x][y] = '0').

**Case d'arrivée**
- On affiche l'image du joueur par-dessus celle de la case d'arrivée. Dans mon projet, l'image exacte dépend de la direction prise par le joueur (gauche, droite, haut, bas) et d'une boucle qui s'incrémente à chaque mouvement puis revient à 0 une fois le max atteint.
- Vérifier si la case d'arrivee est un collectible (map[x][y] == 'C'): si c'est le cas, on decremente le nombre de collectible restants et on met a jour la map (map[x][y] = 'c').
- Vérifier si la case d'arrivée est un collectible ramassé (map[x][y] == 'c'): si c'est le cas, on passe was_collectible à 1.
- Sinon, vérifier si la case d'arrivée est la sortie (map[x][y] == 'E'): si c'est le cas,
  - vérifier si tous les collectibles ont ete ramassés: si c'est le cas, on appele **on_destroy()**.
  - Sinon, on passe was_exit à 1.
- On met à jour la map (map[x][y] = 'P').
