Este es un proyecto base para trabajar con la biblioteca SFML (http://www.sfml-dev.org).

La documentacion de SFML se encuentra en el directorio MinGW/SFML-2.1/doc de ZinjaI (se puede acceder directamente mendiante el último ícono de la barra de herramientas).

En la distribucion para Windows el enlazado de la biblioteca SFML se realiza de forma estatica, para realizarlo contra la version dinamica debe quitar el "-s" al final del nombre de cada libreria en las opciones de enlazado, y la macro "SFML_STATIC" de las opciones de compilación. En este caso tambien sera necesario colocar las dlls que estan en el directorio MinGW/SFML-2.1/bin en un lugar donde el ejecutable pueda encontrarlas (por ejemplo, en la carpeta del proyecto si el ejecutable la utiliza como directorio de trabajo).

