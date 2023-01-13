pipeline {
    agent {
        label "built-in"
    }
    stages {
        stage ("test-branch") {
            steps {
                print env.BRANCH_NAME
            }
        }
        stage ("when-branch") {
            when {
                branch "sandbox/reycheng/feature-1"
            }
            steps{
                print "haha"
            }
        }
        stage ("test-1") {
            steps {
                sh """
                    echo helloworld
                """
            }
        }
    }
}
