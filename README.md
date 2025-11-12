# DAMAS-INTERNACIONALES-PROYECTO
Hecho por 
David Sebastian Prieto Osma
Nicolas Rodriguez Vargas
#  Damas Internacionales (versión mejorada con SFML)

Proyecto de juego de **Damas Internacionales** desarrollado en **C++ y SFML**, enfocado en ofrecer una experiencia visual más moderna e interactiva.  
Esta versión integra un **menú gráfico**, **uso del mouse**, **señalización dinámica de fichas** y **botones interactivos**, mejorando la jugabilidad y la presentación general.

---## Innovación y propósito del cambio

El objetivo principal fue **modernizar la interfaz** y **hacer la experiencia más intuitiva**, alejándonos de una versión basada únicamente en consola o tableros estáticos.  
Con esta mejora, el jugador puede interactuar directamente con los elementos del juego mediante un entorno gráfico completo, utilizando **botones, clics del mouse y efectos visuales**.

###  Objetivos específicos:
1. **Integrar un menú visual (`menu.h`)** para iniciar la partida, consultar reglas o salir del juego.
2. **Permitir control total con el mouse**: selección, movimiento y confirmación de fichas mediante clics.
3. **Destacar la ficha seleccionada** con un color llamativo (amarillo), ayudando a la claridad del turno.
4. **Añadir botones interactivos** en el menú principal que respondan visual y funcionalmente al clic del usuario.
5. **Mejorar la presentación visual** con imágenes, texturas y escalado dinámico en la ventana de 720x720.

---

## Principales mejoras gráficas y funcionales


|  **Uso del mouse** | Se reemplazó la entrada de teclado por clics directos sobre las casillas y los botones del menú. |
|  **Señalización de fichas** | La ficha seleccionada cambia de color para indicar al jugador cuál está activa. |
|  **Menú gráfico (menu.h)** | Se agregó una pantalla de inicio con tres botones: **Iniciar partida**, **Reglas** y **Salir**. |
|  **Escalado automático** | Las texturas del tablero y las fichas se ajustan a la resolución de la ventana (720x720). |
|  **Diseño visual mejorado** | Se integró una imagen de fondo (`assets/menu.jpg`), tipografía personalizada y colores representativos. |
| **Estructura modular** | El código se mantiene organizado: `main.cpp` maneja la lógica del juego y `menu.h` gestiona el menú visual. |

---

##  Cómo funciona el flujo

1. **Inicio del programa →** se carga el menú principal.
2. El usuario puede:
   - *Iniciar partida*: se abre el tablero con las fichas listas para jugar.  
   -  *Reglas*: se muestran en consola las normas básicas del juego.  
   -  *Salir*: cierra la ventana.
3. Durante el juego:
   - Se selecciona una ficha con clic izquierdo.  
   - Al seleccionar un destino válido, la ficha se mueve.  
   - Las capturas y coronaciones se realizan automáticamente.



## Tecnologías utilizadas

- **Lenguaje:** C++  
- **Librería gráfica:** [SFML 3.0](https://www.sfml-dev.org/)  
- **Recursos visuales:** Texturas (`.png`, `.jpg`) y fuentes (`.ttf`)  
- **IDE recomendado:** Visual Studio / Code::Blocks / CLion 

