---
config:
  theme: dark
  layout: fixed
---
```mermaid
flowchart TB
 subgraph Sensors["Sensors"]
        Camera["Camera Sensors"]
        Speed["Speed Sensors"]
        Other["Other Sensors"]
  end
 subgraph Features["Features"]
        DD["Drowsiness Detection"]
        RD["Reckless Driving Detection"]
        DIS["Distraction Detection"]
        SB["Seatbelt Detection"]
  end
 subgraph Vehicle["Vehicle"]
        ADAS["ADAS Containers"]
        ROS2["ROS2 Middleware"]
        Sensors
        Features
  end
 subgraph subGraph3["Cloud Infrastructure"]
        Server["Update Server"]
        CI/CD["GitLab CI/CD"]
        Models["AI Models"]
  end
 subgraph subGraph4["User App"]
        App["Owner's App"]
        Notifications["Alert Notifications"]
  end
    Sensors --> ADAS
    ADAS --> Features
    Server -- OTA Updates --> ADAS
    CI/CD --> Server
    Features -- Alerts --> App
    App --> Notifications
    Models -- Model Updates --> Server