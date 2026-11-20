# Licences

Copyright © 2026 Alexian ([github.com/alexj0i](https://github.com/alexj0i))

## Le projet : CC BY-NC-SA 4.0

Tout le dépôt (matériel, firmware, documentation, Gerbers) est sous licence [Creative Commons Attribution - Pas d'utilisation commerciale - Partage dans les mêmes conditions 4.0](LICENSE), sauf les fichiers de bibliothèque KiCad listés plus bas.

**Autorisé :** fabriquer les cartes pour soi, les modifier, partager les fichiers ou ses modifications, en citant l'auteur et le lien vers ce dépôt.

**Interdit sans mon accord écrit :**
- vendre les cartes, en kit ou montées ;
- vendre les fichiers ;
- utiliser le projet dans un produit ou un service commercial.

**Partage dans les mêmes conditions :** une version modifiée doit être publiée sous la même licence. Elle ne peut donc pas devenir commerciale.

Pour un usage commercial, contactez-moi via GitHub.

Aucune garantie : le montage utilise une haute tension de 170 V, chacun le réalise à ses risques.

## Éléments issus des bibliothèques officielles KiCad

Ces fichiers proviennent des bibliothèques KiCad (© KiCad Community, <https://gitlab.com/kicad/libraries>). Ils restent sous leur licence d'origine, **CC-BY-SA 4.0**, avec l'exception suivante :

> To the extent that the creation of electronic designs that use 'Licensed Material' can be considered to be 'Adapted Material', then the copyright holder waives article 3 of the license with respect to these designs and any generated files which use data provided as part of the 'Licensed Material'.

Les cartes qui utilisent ces empreintes et symboles restent sous la licence du projet (CC BY-NC-SA 4.0). Seuls les fichiers de bibliothèque ci-dessous restent sous CC-BY-SA 4.0.

| Fichier | Origine | Modification |
|---|---|---|
| `carte_mere_in12/carte_mere_in12.pretty/C_Disc_D3.0mm_W1.6mm_P2.50mm.kicad_mod` | Capacitor_THT | aucune |
| `carte_mere_in12/carte_mere_in12.pretty/CP_Radial_D5.0mm_P2.00mm.kicad_mod` | Capacitor_THT | aucune |
| `carte_mere_in12/carte_mere_in12.pretty/DIP-16_W7.62mm.kicad_mod` | Package_DIP | courtyard réduit au corps du boîtier |
| `carte_mere_in12/carte_mere_in12.pretty/PinHeader_1x02_P2.54mm_Vertical.kicad_mod` | Connector_PinHeader_2.54mm | aucune |
| `carte_mere_in12/carte_mere_in12.pretty/PinHeader_2x04_P2.54mm_Vertical.kicad_mod` | Connector_PinHeader_2.54mm | aucune |
| `carte_mere_in12/carte_mere_in12.pretty/MountingHole_2.2mm_M2.kicad_mod` | MountingHole | aucune |
| `porte_tube_in12/porte_tube_in12.pretty/MountingHole_2.2mm_M2.kicad_mod` | MountingHole | aucune |
| `porte_tube_in12/porte_tube_in12.pretty/R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal.kicad_mod` | Resistor_THT | aucune |
| `carte_mere_in12/carte_mere_in12.pretty/HT_1x03_Cle2.kicad_mod` | dérivée de PinHeader_1x03_P2.54mm_Vertical | renommée, broche 2 remplacée par un trou non métallisé |
| `carte_mere_in12/carte_mere_in12.pretty/Support_1x07_Gauche.kicad_mod` | dérivée de PinSocket_1x07_P2.54mm_Vertical | renommée, position 7 en trou non métallisé, sérigraphie et courtyard modifiés, modèle 3D retiré |
| `carte_mere_in12/carte_mere_in12.pretty/Support_1x07_Droite.kicad_mod` | dérivée de PinSocket_1x07_P2.54mm_Vertical | renommée, position 6 en trou non métallisé, sérigraphie et courtyard modifiés, modèle 3D retiré |
| symboles `+5V`, `GND`, `PWR_FLAG` dans `carte_mere_in12/carte_mere_in12.kicad_sym` | bibliothèque `power` | aucune |

Les autres empreintes et symboles (`Nixie_IN-12_Douilles_1mm`, `Barrette_1x07*`, `SN74141`, `IN-12B`, `Support_*`, `Conn_*`, etc.) sont propres au projet et suivent la CC BY-NC-SA 4.0.
