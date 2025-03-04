# 42solong
Projet du 3eme cercle du cursus 42

# Strategie
1. Parsing d'une map
2. Gestion des erreurs (map invalide)
3. Dessiner / trouver les sprites
4. Transformer les 1/0/e/p/c en images
5. Creer une nouvelle fenetre qui bouge pas si focus sur une autre / reduite
6. Implementer les inputs clavier avec affichage du nombre de mouvements dans terminal
7. Implementer condition de victoire: parcourir la map pour savoir combien de collectibles, tant que pas tout ramasse sortie fermee, quand tout ramasse sortie ouverte, quand sort = "you win".
8. Creer plusieurs maps fonctionnelles

# Parsing
Transformer la map en tableau de char: utiliser get_next_line() une premiere fois pour compter le nombre de lignes et allouer la taille du tableau, puis reutiliser get_next_line() alouer la taille de chaque ligne et les remplir.

# Gestion des erreurs
Verifier si:
- la map fait au minimum 3 lignes et 5 cases de largeur.
- la map est rectangulaire.
- la map est entouree de murs (1).
- la map est jouable:
  - la map a un seul joueur (P)
  - la map a une seule sortie (E)
  - la map a au moins 1 collectible (C)
  - chaque element est atteignable par le joueur

Faire des maps tests pour chaque erreur.