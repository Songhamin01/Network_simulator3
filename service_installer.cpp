#include "service_installer.h"

// 호스트와 서비스 사이의 관계를 설정한다.
void ServiceInstaller::install(Host *host, Service *service)
{
    host->services_.push_back(service);
}