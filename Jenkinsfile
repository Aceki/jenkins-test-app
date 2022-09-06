pipeline {
    agent any // <- Определяет агентов, на которых будет будет выполнятся конвейера.
    parameters { // <- Параметры конвейера.
        choice(name: "TEST_ENABLED", choices: ["OFF", "ON"], description: "Включает сборки тестов.")
    }
    stages {                                    // <- Список этапов
        stage("build") {                        // <- Этап 'Сборка'. В кавычках указывается название этапа.
            steps {                             // <- Шаги
                sh "mkdir build && cd build"
                sh "cmake .. -DTEST_ENABLED=${params.TEST_ENABLED}"
            }

//            post {}                             // <- Действия по завершении этапа 'Сборка'
        }

        stage("test") {                         // <- Этап 'Тестирование'
            steps {
                echo "Testing"
            }
        }
    }

//    post {}                                     // <- Действия по завершении всех этапов
}
