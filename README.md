# Horloge nixie IN-12

Afficheur 4 chiffres à tubes nixie **IN-12A / IN-12B**, piloté par un **Arduino Uno**.
Un décodeur **SN74141 / K155ID1** par tube (pilotage statique), haute tension **170 V** fournie par un module **NCH6100HV**.
Chaque tube est monté sur son propre porte-tube, enfiché sur la carte mère.

## Contenu

| Dossier | Contenu | État |
|---|---|---|
| `porte_tube_in12/` | Porte-tube individuel 25,4 × 36 mm, tube sur 12 douilles Ø 1 mm, R d'anode 12 kΩ | v1.0 terminé |
| `porte_tube_in12/fabrication/` | Gerbers + perçages prêts pour JLCPCB | à jour avec v1.0 |
| `carte_mere_in12/` | Carte mère 114,3 × 36 mm : 4 supports de porte-tubes, 4 × SN74141, connecteurs | v0.2, routage en cours |
| `carte_mere_in12/docs/` | Schéma de la carte mère en PDF | v0.2 |
| `firmware/nixie_in12/` | Programme Arduino (horloge, affichage d'un nombre, anti-empoisonnement) | fonctionnel |

Projets KiCad 10. Les symboles et empreintes sont dans chaque dossier de projet (`*.kicad_sym`, `*.pretty`) : rien à installer.

## Carte mère : connecteurs

| Réf. | Rôle | Broches |
|---|---|---|
| J1–J8 | Supports des porte-tubes (gauche / droite de V1…V4) | gauche : K5 K4 K3 K2 K1 virgule – ; droite : K6 K7 K8 K9 K0 (clé) **+HT** |
| J9 | Commande V1, V2 (2×4, au dos) | 1-4 : V1 A B C D · 5-8 : V2 A B C D |
| J12 | Commande V3, V4 (2×4, au dos) | 1-4 : V3 A B C D · 5-8 : V4 A B C D |
| J10 | Logique (au dos) | 1 : +5 V · 2 : GND |
| J11 | Haute tension (au dos) | 1 : **+HT 170 V** · 2 : clé · 3 : GND |

Câblage vers l'Uno attendu par le programme (`BCD_PIN`) :

| Tube | A | B | C | D |
|---|---|---|---|---|
| V1 (J9 1-4) | D13 | D11 | D10 | D12 |
| V2 (J9 5-8) | D9 | D7 | D6 | D8 |
| V3 (J12 1-4) | D5 | D3 | D2 | D4 |
| V4 (J12 5-8) | A3 | A1 | A0 | A2 |

Masse commune entre l'Arduino, la carte mère et le module HT.

## Programme

Moniteur série 9600 bauds, fin de ligne « Nouvelle ligne » :
`T1435` règle l'heure à 14:35 · `N42` affiche 42 · `H` retour à l'horloge · `C` défilement anti-empoisonnement.

## Reste à faire

- Carte mère : relier le +5 V entre V1, V2 et V3, et la masse de C1 ; DRC à 0 avant commande.
- Mesurer le diamètre de la queue des douilles (perçage prévu pour 0,5–0,75 mm).
- Vérifier le brochage sur un vrai tube avant de souder (anode = broche 1).
- Option : points de séparation INS-1 dans l'espace central de la carte mère.

## Sécurité

170 V continu sur les porte-tubes et J11. Débrancher l'alimentation et attendre que la sortie HT soit sous 10 V avant de toucher la carte.

## Travailler sur deux PC

Un seul PC à la fois sur un même projet : **Fetch/Pull** avant d'ouvrir KiCad, **Commit + Push** après l'avoir fermé.

## Licence

[CC BY-NC-SA 4.0](LICENSE) : fabrication et modifications libres pour un usage personnel, en citant l'auteur. **Vente et usage commercial interdits** sans accord écrit. Les versions modifiées doivent être publiées sous la même licence.
Quelques empreintes et symboles viennent des bibliothèques KiCad et restent sous CC-BY-SA 4.0 : voir [LICENCES.md](LICENCES.md).

Projet fourni sans garantie. Il utilise une haute tension de 170 V : si vous le reproduisez, c'est à vos risques.
