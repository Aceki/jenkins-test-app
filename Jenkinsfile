pipeline {
    agent any // <- Определяет агентов, на которых будет будет выполнятся конвейера.
    parameters { // <- Параметры конвейера.
        choice(name: "TEST_ENABLED", choices: ["OFF", "ON"], description: "Включает сборки тестов.")
        string(name: "Build directory")
    }
    options {
        skipDefaultCheckout(true)
    }
    stages {                                    // <- Список этапов
        stage("build") {                        // <- Этап 'Сборка'. В кавычках указывается название этапа.
            steps {                             // <- Шаги
                cleanWs()
                checkout scm
                sh "mkdir build && cmake -B build -DTEST_ENABLED=${params.TEST_ENABLED}"
            }

//            post {}                             // <- Действия по завершении этапа 'Сборка'
        }

        stage("test") {                         // <- Этап 'Тестирование'
            steps {
                echo "Testing"
            }
        }
    }

    post {                                     // <- Действия по завершении всех этапов
        always {
            cleanWs(
                cleanWhenNotBuilt: false,
                deleteDirs: true,
                disableDeferredWipeout: true,
                notFailBuild: true,
                patterns: [
                    [pattern: '.gitignore', type: 'INCLUDE'],
                    [pattern: '.propsfile', type: 'EXCLUDE']
                ]
            )
        }
    }
}
