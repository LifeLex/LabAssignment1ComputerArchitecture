#include "profesor.h"

Profesor::Profesor()
{

}

Profesor::~Profesor()
{

}


//Funciones sobrecargadas para añadir alumnos con 1, 2, 3 notas
void Profesor::calificar(float nota1, Estudiante *alumno)
{
    alumno->setNotas(nota1);
}

void Profesor::calificar(float nota1, float nota2, Estudiante *alumno)
{
    alumno->setNotas(nota1);
    alumno->setNotas(nota2);
}

void Profesor::calificar(float nota1, float nota2, float nota3, Estudiante *alumno)
{
    alumno->setNotas(nota1);
    alumno->setNotas(nota2);
    alumno->setNotas(nota3);
}

//Añadir estudiante al listado
void Profesor::nuevoEstudiante(Estudiante *alumno)
{
    estudiantes.push_back(*alumno);
}

//Hacer la media y seleccionar la mejor media
vector <float> medias;

void Profesor::media(Estudiante *estudiante)
{
    //calculo la media
    vector<int> n = estudiante->getNotas();
    float media=0;
    for (int i=0;i<n.size();i++) {
        media= media+n[i];
    }
    media=media/n.size();

    if (n.size()>=3) {
        cout<<"La media del alumno es "<< media<<endl;
        medias.push_back(media);
    }else {
        cout<<"No hay notas suficientes en el sistema para calificar al alumno"<<endl;
        medias.push_back(0);
    }


}

void Profesor::mejorMedia()
{
    float mejorMedia=0;
    string mejorAlumno;

    for (int i=0;i<medias.size();i++) {
        if (medias[i]>mejorMedia) {
            mejorMedia= medias[i];
            mejorAlumno= estudiantes[i].getNombre();
        }
    }

    cout<< "La mejor media ha sido "<< mejorMedia << " del estudiante "<<mejorAlumno <<endl;
}


void Profesor::imprimir(Persona *persona)
{
cout << "Nombre: "<< persona->getNombre()<<endl;
//cout << "Apellido "<< persona->getApellido()<<endl;
cout << "DNI: "<< persona->getDNI()<<endl;

}
