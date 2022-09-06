pipeline {
    agent any

    parameters {
        choice(name: "TEST_ENABLED", choices: ["OFF", "ON"], description: "Включает сборки тестов.")
        string(name: "Build directory")
    }

    options {
        skipDefaultCheckout(true)
    }

    stages {
        stage("build") {
            steps {
                cleanWs()
                checkout scm
                dir("build") {
                    sh "cmake .. -DTEST_ENABLED=${params.TEST_ENABLED}"
                    sh "make -j`nproc`"
                }
            }
        }

        stage("test") {
            when { environment name: "TEST_ENABLED", value: "ON" }

            steps {
                dir("build") {
                    sh "make test"
                }
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
