# WASM Newton-Raphson
Ce dépot contient les fichiers nécessaires à la réalisation de l'exemple donné dans [cet article](https://blog.esciencecenter.nl/using-c-in-a-web-app-with-webassembly-efd78c08469).
Bien que les fichiers compilés soient à disposition, il est indiqué les méthodes pour recompiler soit-même le code c++, à l'aide du [docker officiel](https://hub.docker.com/r/emscripten/emsdk) emscripten ou via l'installation classique. 

> Il est nécessaire de lancer un **serveur web** pour pouvoir tester le bon fonctionnement du code. Une instruction simple est donnée à la fin de ce document à cet effet.

### Compiler un programme simple depuis le conteneur
```sh
docker run \
  --rm \
  -v $(pwd):/src \
  -u $(id -u):$(id -g) \
  emscripten/emsdk \
  emcc nom_du_programme.cpp -o nom_en_sortie.js #optionel
```
## Compiler le projet
### Newton Raphson compilation offline
```sh
emcc -I. -o newtonraphson.js -Oz -s MODULARIZE=1 -s EXPORT_NAME=createModule --bind problem.cpp newtonraphson.cpp bindings.cpp
```
### Newton Raphson compilation avec docker
```sh
docker run \
  --rm \
  -v $(pwd):/src \
  -u $(id -u):$(id -g) \
  emscripten/emsdk \
  emcc -I. -o newtonraphson.js -Oz -s MODULARIZE=1 -s EXPORT_NAME=createModule --bind problem.cpp newtonraphson.cpp bindings.cpp
```

## Lancer un serveur permettant d'exécuter le code
`python3 -m http.server "numéro de port"`
ex : `python3 -m http.server 8000`
> A lancer **impérativement** dans le dossier contenant les fichiers compilés. 
