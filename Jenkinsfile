pipeline {
    agent any

    parameters {
        choice(name: "TEST_ENABLED", choices: ["ON", "OFF"], description: "Активирует сборку и запуск тестов.")
        choice(name: "DOCS_ENABLED", choices: ["ON", "OFF"], defaultValue: "OFF", description: "Активирует генерацию документации.")
    }

    options {
        skipDefaultCheckout(true)
    }

    stages {
        stage("Build") {
            steps {
                cleanWs()
                checkout scm
                dir("build") {
                    sh "cmake .. -DTEST_ENABLED=${params.TEST_ENABLED}"
                    sh "make -j`nproc`"
                }
            }
        }

        stage("Test - Unit testing") {
            when { environment name: "TEST_ENABLED", value: "ON" }

            steps {
                dir("build") {
                    sh "make test"
                }
            }
        }

        stage("Info - Generate documentation") {
            when { environment name: "DOCS_ENABLED", value: "ON" }

            steps {
                sh "doxygen"
                sh "mkdir docs && mv html/ docs/"
            }
        }
    }

    post {
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
