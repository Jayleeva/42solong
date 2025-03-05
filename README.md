# 42solong
Projet du 3eme cercle du cursus 42

# Strategie
1. Parsing d'une map
2. Gestion des erreurs (map invalide)
3. Dessiner / trouver les sprites
4. Transformer les 1/0/e/p/c en images
5. Creer une nouvelle fenetre qui bouge pas si focus sur une autre / reduite
6. Afficher les images correctement (layering, déplacements, collecte)
7. Implementer les inputs clavier avec affichage du nombre de mouvements dans terminal + fermeture correcte du programme
8. Implementer condition de victoire: parcourir la map pour savoir combien de collectibles, tant que pas tout ramasse sortie fermee, quand tout ramasse sortie ouverte, quand sort = "you win".
9. Creer plusieurs maps fonctionnelles

# Parsing
Transformer la map en tableau de char: utiliser **get_next_line()** une premiere fois pour compter le nombre de lignes et allouer la taille du tableau, puis reutiliser **get_next_line()** pour allouer la taille de chaque ligne et les remplir avec **ft_memcpy()**. Fermer le fichier a la fin des deux get_next_line(); faire les deux dans des fonctions differentes pour ne pas avoir besoin de fseek().

# Gestion des erreurs
Verifier si:
- le fichier est bien une map (.ber)
- la map fait au minimum 3 lignes et 5 cases de largeur.
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
- Le transparent est considéré comme du blanc par linux. Dans les XPM où il doit y avoir du transparent, il faut remplacer le "none" par "ffffff", et donc ne pas utiliser de blanc pur dans les dessins.

# Implémenter la minilibx
Cauchemar
Cauchemar
Cauchemer

# Créer une nouvelle fenêtre
- Créer une structure
- Faire une fonction qui appelle **mlx_init()** sur le mlx_ptr de la structure
- Puis qui appelle **mlx_new_window()** sur le win_ptr de la structure
- Puis qui appelle **mlx_loop()** sur le mlx_ptr de la structure pour être prêt à recevoir les inputs à tout moment

# Poser les images
- Convertir les PNG en XPM via un site de conversion (https://to.imagestool.com/png-to-xpm), mettre les XPM dans les sources?
- Donner le chemin relatif des images à mlx_xpm_file_to_imag() pour les charger; stocker les adresses des images
- Passer ces adresses à mlx_put_image_to_window() pour placer les images sur la fenêtre, en fonction de la map (initialiser et mettre à jour)
- Faire en sorte que le joueur soit posé par-dessus le décor (layering)

# Implémenter les inputs
Utiliser mlx_key_hook()?

- Si hook == KEY_A : décaler joueur d'une case vers la gauche
- Si hook == KEY_W : décaler joueur d'une case vers le haut
- Si hook == KEY_S : décaler joueur d'une case vers le bas
- Si hook == KEY_D : décaler joueur d'une case vers la droite

etc.

# Faire fermer le programme correctement
Si cliqué sur la croix ou appuyé sur ESC ou Q, OU si gagné:
- Ne pas oublier les free()!
- Utiliser mlx_destroy_image(), mlx_destroy_window() et mlx_destroy_display() pour éviter les still reachable
- Puis utiliser exit() pour fermer le programme
