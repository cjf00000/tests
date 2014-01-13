name := "trybreeze"

version := "0.1"

libraryDependencies  ++= Seq(
            // other dependencies here
            // pick and choose:
            "org.scalanlp" % "breeze_2.10" % "0.5.2",
            "org.scalanlp" % "breeze-viz_2.10" % "0.5.2"
)

resolvers ++= Seq(
            // other resolvers here
            // if you want to use snapshot builds (currently 0.6-SNAPSHOT), use this.
            "Sonatype Snapshots" at "https://oss.sonatype.org/content/repositories/snapshots/",
            "Sonatype Snapshots" at "https://oss.sonatype.org/content/repositories/releases/"
)


//snapshots:
libraryDependencies  ++= Seq(
            // other dependencies here
            // pick and choose:
            "org.scalanlp" %% "breeze" % "0.6-SNAPSHOT",
            "org.scalanlp" %% "breeze-viz" % "0.5-SNAPSHOT"
)
