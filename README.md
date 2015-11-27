# micromachines
## Como colocar as texturas a funcionar

### Primeiros passos
Copiar a pasta SOIL para a diretoria glut/include

Copiar o ficheiro `SOIL.lib` para `glut/SOIL/lib`

### Alterações no Visual Studio
No Visual studio, ir às propriedades do projecto (alt+enter):

	*VC++ Directories > Library Directories > Edit...*

		- adicionar `glut/SOIL/lib`

	*Linker > Input > Aditional Dependencies > Edit...*
	
		- adicionar o ficheiro `SOIL.lib`

### Alterações no código
No código, ficheiro `roadside.cpp`

	- trocar o *caminho absoluto* para o ficheiro `plank.jpg` para o correspondente no vosso pc