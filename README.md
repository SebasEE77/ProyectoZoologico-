# Proyecto Zoológico
### Integrantes: Juan Manuel Hurtado y Sebastián Enríquez

#### Contexto 
Nuestro proyecto trata de simular un zoológico el cual se compone de distintos hábitats escritos por el usuario, en este caso solo se podrían 4, el hábitat desértico, acuático, polar y selvático. La idea es que dentro de esos hábitats haya animales con ciertas características, las cuales el usuario determinara para que finalmente se pueda interactuar con cada animal, ya sea agregando o editando la dieta del animal dependiendo de su tipo de alimentación, que sería carnívoro, herbívoro u omnívoro, y también interactuar de acuerdo con varias acciones que el animal podrá hacer, siendo comer, dormir o jugar.

#### Introducción 
El proyecto consta de 4 archivos .cpp y 3 archivos .h, es decir, hay 3 clases en el proyecto las cuales cada una tiene un archivo .cpp y un archivo .h, el sobrante sería el main .cpp. En primer lugar, la primera clase tiene como nombre Zoológico, el cual tiene la principal función de crear el zoológico con un nombre y por consiguiente crearía los distintos hábitats a gusto del usuario, puesto que se van a guardar en un vector tipo Hábitat y, si el usuario desea, podría mirar todos los hábitats que ha creado. En segundo lugar, está la clase Hábitat la cual crea los animales de acuerdo con las características hechas por el usuario, en el que se van a guardar en un vector tipo Animal, asimismo, si el usuario desea podrá ver la información de cualquier animal que esté en el vector. En tercer lugar, está la clase Animal la cual se enfoca más que todo en manejar la dieta de cada animal, preguntándole al usuario que comida desearía agregar al vector tipo string de la dieta, claramente de acuerdo a su tipo de alimentación y a una lista de comida ya establecida, también, maneja las acciones donde cada una se agregaría a un vector tipo Animal de acuerdo a lo que el usuario haya escogido.

#### Funcionamiento
El programa en sí tiene un buen funcionamiento, en el main claramente hay un menú con varias opciones para que el usuario elija y cada opción en el switch tiene un método el cual hace exactamente lo que el usuario pide. En términos generales, a la hora de correr el programa va a aparecer un menú con distintas opciones, y el usuario escoge cuál, por ejemplo, escoge la primera opción, entonces en el switch se para en el case 1 y llama al método que haya ahí, en este caso el método está en el main donde se pide información, luego de eso, dentro de ese método se llama a otro de la clase zoológico donde hace el trabajo propio de lo que el usuario le pide hacer, en este caso, seria crear un hábitat con un nombre el cual se agrega al vector de hábitats, asimismo ocurre cuando el usuario escoge la segunda opción, se llama al método que está en el main donde se pide datos al usuario para crear un animal y entonces haría el mismo proceso que la primera. Como es posible ver, pasa esto en la mayoría de los casos, ya que se necesita pedir información al usuario donde normalmente lo hacemos en el main, y así luego se pueda ejecutar cada método que se llama donde hace el proceso necesario de acuerdo a lo que pide el usuario. Hay que tener en cuenta que cada clase tiene sus respectivos atributos y el nombre de los métodos en el .h, mientras que en el .cpp está el desarrollo de cada método creado en el .h, por ejemplo, a la hora de agregar o editar una dieta, en el menú se llama al método correspondiente de esa acción, como el método está en una clase Animal, entonces en animales .cpp va a estar todo el proceso que involucra realizar esta acción y cuando lo haga en la terminal va a aparecer el resultado de lo que el usuario pidió. Cabe mencionar que es posible acceder a los atributos de cada clase con los métodos de acceso, es decir los gets y sets de cada atributo ubicados en el .h, los cuales se podrían manejar en cualquier clase pero llamándolos con el respectivo apuntador de su propia clase. Finalmente, se podría decir que la ejecución del programa es bastante sencilla, ya que cuando comienza y aparezca el menú, el usuario solamente escribe un número escogiendo la opción del menú, y dentro de cada opción van a mostrarse detalladamente instrucciones de lo que el usuario deberá realizar para poder conseguir lo que esa opción del menú brinda. De esta misma forma, si el usuario se equivoca a la hora de escribir o hace bien lo que le piden, siempre habrá un mensaje de que lo ha logrado o de que no se ha hecho para que lo tenga en cuenta y así sepa qué hacer después.

#### Evidencias
A continuación se mostrará como evidencia que el programa funciona correctamente.

###### El programa comienza con este menú.
![image](https://user-images.githubusercontent.com/105950433/230791096-4e44b598-5f60-4919-8f95-eedf58661d32.png)
###### Para añadir un hábitat se selecciona la opción 1 y se escribe un hábitat de los 4 que se muestra en la pantalla. Se presenta el mensaje que se agrego.
![image](https://user-images.githubusercontent.com/105950433/230791177-afe4e6fe-b419-4320-9f07-66c68000e01f.png)
###### Para añadir un animal se selecciona la opción 2 y se escribe las características del animal. Se muestra si se agrego.
![image](https://user-images.githubusercontent.com/105950433/230791358-437676ca-3f60-43ad-a01b-c8b9a4fa1686.png)
###### Si quiere ver qué hábitats hay en el zoológico escoge la opción 3 y en el caso de animales sería la opción 4.
![image](https://user-images.githubusercontent.com/105950433/230791466-a5c17f52-b28c-47a4-93d7-99f3f4de980c.png)
###### Si se necesita ver la información de un animal en específico selecciona la opción 5, ingresando el hábitat y el id del animal que quiera ver. 
![image](https://user-images.githubusercontent.com/105950433/230791533-a40790af-5c17-4ea5-9ed5-0feed8de6842.png)
###### Será posible agregar una comida al animal con la opción 6 del menú, el cual tocará ingresar el hábitat y el id del animal, después, se presentará un sub-menú donde se escogerá la opción 2 para agregar una comida de una lista ya establecida.
![image](https://user-images.githubusercontent.com/105950433/230791755-501e6620-c3cc-42f8-9bfe-378830a26509.png)
###### Para ver la dieta del animal se hace lo mismo que antes, sino que en el sub-menú selecciona la opcioón 1.
![image](https://user-images.githubusercontent.com/105950433/230792267-b0de8a8a-14a5-4a8c-a611-1451e1f61eda.png)
###### Para modificar o eliminar una comida pasa los mismo que en el caso anterior, sin embargo, en el sub-menú se escoge la opción 3, luego escoge la opción 1 que es modificar u opción 2 que es eliminar, y se escribe la comida que quiera modificar o eliminar.
###### Modificar:
![image](https://user-images.githubusercontent.com/105950433/230792104-e9daff06-4ed2-4afb-9b77-08789bbc2f91.png)
###### Resultado modificado:
![image](https://user-images.githubusercontent.com/105950433/230792544-b7f5147b-5763-452a-b6d8-6d6762f5ab5a.png)
###### Eliminar:
![image](https://user-images.githubusercontent.com/105950433/230794121-835afca6-13fa-4f31-a592-99425d21e78c.png)
###### Resultado eliminado:
![image](https://user-images.githubusercontent.com/105950433/230792649-6e9803b3-59f6-444a-90aa-f77641c0cebf.png)
###### Será posible tener interacciones con los animales del zoológico escribiendo la opción 7 del menú principal, el cual tocará ingresar el hábitat y el id del animal, después, se presentará un sub-menú donde se podrá escoger jugar, comer o dormir. 
###### En el caso de jugar se elige la opción 1, donde habrá un pequeño juego con el animal. Solo el usuario tiene 3 intentos:
![image](https://user-images.githubusercontent.com/105950433/230793022-4b861b0f-0a7c-4bf8-a4ef-fd862a973b70.png)
###### En el caso de comer se elige la opción 2, donde será obligatorio agregar una comida a la dieta del animal, ya que aquí se le da una comida nueva relacionado a su dieta.
![image](https://user-images.githubusercontent.com/105950433/230793270-3307afb6-cabc-4e5e-a7ae-20b130446f11.png)
###### Finalmente, en el caso de dormr, se elige la opción 3 puesto que aquí se escribe la cantidad de horas exactas que debe dormir el animal de acuerdo a lo que el usuario escribió justamente cuando creó el animal. 
![image](https://user-images.githubusercontent.com/105950433/230794215-87c90011-4a3c-44b7-812c-f2b39b765cc1.png)
###### El usuario escribió 6 horas así que se pone las 6 horas:
![image](https://user-images.githubusercontent.com/105950433/230793391-c38a8812-98d7-4546-8825-46d100d232d5.png)
